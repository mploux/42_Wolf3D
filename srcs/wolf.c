/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:12:44 by mploux            #+#    #+#             */
/*   Updated: 2017/07/27 23:11:27 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "maths.h"
#include "graphics.h"
#include <stdlib.h>

int		create_wolf(t_data *data, const char *name, int width, int height)
{
	t_win		*win;

	if (!(win = (t_win *)ft_memalloc(sizeof(t_win))))
		error("malloc error !");
	data->thread_num = 16;
	if (!(data->threads = (t_thread *)ft_memalloc(sizeof(t_thread) * data->thread_num)))
		error("malloc error !");
	data->win = win;
	new_sdl_display(data, name, width, height);
	data->input = new_input();
	data->framebuffer = new_bitmap(data, width, height);
	data->cam_rot = vec2(0, 0);
	data->cam_angle = 0;
	data->colors[0] = vec3(255, 0, 0);
	data->colors[1] = vec3(0, 255, 0);
	data->colors[2] = vec3(0, 0, 255);
	data->colors[3] = vec3(255, 255, 0);
	data->colors[4] = vec3(0, 255, 255);
	return (1);
}

void	draw_debug(t_data *data)
{
	int y;

	y = data->win->h;
	draw_text(data, vec2(5, y - 25), 0xffffff, "Ecole 42 - Wolf3D - mploux");
}

int		loop(t_data *data)
{
	data->cam_rot = vec2(cos(DTR(data->cam_angle)), sin(DTR(data->cam_angle)));
	manage_inputs(data, data->input);
	draw_scene(data);
	bitmap_update(data->framebuffer);
	draw_debug(data);
	return (1);
}

void	loop_wolf(t_data *data)
{
	sdl_loop(data, &loop);
}

void	exit_wolf(t_data *data)
{
	free(data->input);
	free(data);
	exit(0);
}
