/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 07:17:04 by mploux            #+#    #+#             */
/*   Updated: 2017/01/05 08:55:02 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		draw_player(t_data *data)
{
	t_vec2	cam_pos;
	t_vec2	cam_dir;

	cam_pos = vec2(data->cam_pos.x * 10 + 2.5, data->cam_pos.z * 10 + 2.5);
	cam_dir = vec2(cam_pos.x + data->cam_rot.x * 8,
					cam_pos.y + data->cam_rot.y * 8);
	draw_quad(data, cam_pos, vec2(3, 3), 0xffffff);
	draw_quad(data, cam_dir, vec2(2, 2), 0xaaaaaa);
}

static void		draw_tile(t_data *data, t_vec2 pos, t_vec3 col)
{
	int		x;
	int		y;
	double	xx;
	double	yy;
	double	dist;

	y = -1;
	while (++y < 10)
	{
		x = -1;
		while (++x < 10)
		{
			xx = data->cam_pos.x * 10 - pos.x - x;
			yy = data->cam_pos.z * 10 - pos.y - y;
			dist = clamp(1.0 / sqrt(xx * xx + yy * yy) * 10, 0, 1);
			draw_pix(data, pos.x + x, pos.y + y, color(vec3_mul_d(col, dist)));
		}
	}
}

static void		draw_bg(t_data *data, t_vec2 size, t_vec3 col)
{
	int		x;
	int		y;
	double	xx;
	double	yy;
	double	dist;

	y = -1;
	while (++y < size.y)
	{
		x = -1;
		while (++x < size.x)
		{
			xx = data->cam_pos.x * 10 - x;
			yy = data->cam_pos.z * 10 - y;
			dist = clamp(1.0 / sqrt(xx * xx + yy * yy) * 10, 0, 1);
			draw_pix(data, x, y, color(vec3_mul_d(col, dist)));
		}
	}
}

void			draw_minimap(t_data *data)
{
	int		x;
	int		y;
	int		tile;
	t_vec3	col;
	t_vec2	size;

	y = -1;
	size = vec2(10 * data->size.x + 4, 10 * data->size.y + 4);
	draw_bg(data, size, vec3(50, 50, 50));
	while (++y < data->size.y)
	{
		x = -1;
		while (++x < data->size.x)
		{
			if ((tile = data->map[x + y * (int)data->size.x]) == '0')
				continue;
			col = data->colors[tile - '0' - 1];
			draw_tile(data, vec2(x * 10 + 2, y * 10 + 2), col);
		}
	}
	draw_player(data);
}
