/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 06:07:02 by mploux            #+#    #+#             */
/*   Updated: 2017/08/04 18:48:09 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "maths.h"

static void		draw_floor_and_ceiling(t_data *data, double x, double y)
{
	double	dist;
	double	fog;
	int		side;

	if (y < data->win->h / 2 + 1)
	{
		draw_pix(data, x, y, 0);
		return;
	}
	side = y < data->win->h / 2 ? -1 : 1;
	dist = ((double)data->win->h / (y - data->win->h / 2.0) * side);
	fog = 255.0 / clamp(dist, 1, 10000);
	draw_pix(data, x, y, color(vec3(fog, fog, fog)));
}

static void		draw_vertical_wall(t_data *data, int x, t_ray ray, t_vec3 col)
{
	double y;
	double h;
	double start;
	double end;
	double fog;

	h = (int)(data->win->h / ray.dist / 2.0);
	start = clamp(data->win->h / 2 - h / 2, 0, data->win->h);
	end = clamp(data->win->h / 2 + h / 2, 0, data->win->h);
	y = -1;
	fog = 1.0 / clamp(ray.dist + 1, 1, 10000);
	col = vec3_mul_d(col, fog);
	while (++y < data->win->h)
	{
		if (y >= start && y <= end)
			draw_pix(data, x, y, color(col));
		else
			draw_floor_and_ceiling(data, x, y);
	}
}

static void		*draw_walls(void *t)
{
	double	x;
	t_ray	ray;
	t_vec2	dir;
	double	angle;
	double	asp;

	asp = (double)((t_thread *)t)->data->win->w / (double)((t_thread *)t)->data->win->h;
	x = ((t_thread *)t)->x;
	while (++x <= ((t_thread *)t)->x + ((t_thread *)t)->width)
	{
		angle = x / ((t_thread *)t)->data->win->w * 2 - 1;
		dir.x = ((t_thread *)t)->data->cam_rot.x - (angle * asp) * ((t_thread *)t)->data->cam_rot.y;
		dir.y = ((t_thread *)t)->data->cam_rot.y + (angle * asp) * ((t_thread *)t)->data->cam_rot.x;
		ray = throw_ray(((t_thread *)t)->data, ((t_thread *)t)->data->cam_pos, dir);
		draw_vertical_wall(((t_thread *)t)->data, (int)x, ray, ray.color);
	}
	return (0);
}

void			draw_scene(t_data *data)
{
	int			x;
	t_thread	*thread;

	x = -1;
	while (++x < data->thread_num)
	{
		thread = &data->threads[x];
		thread->width = data->win->w / data->thread_num;
		thread->x = x * thread->width;
		thread->data = data;
		pthread_create(&thread->id, NULL, &draw_walls, thread);
	}
	x = -1;
	while (++x < data->thread_num)
	{
		thread = &data->threads[x];
		pthread_join(thread->id, NULL);
	}
	draw_minimap(data);
}
