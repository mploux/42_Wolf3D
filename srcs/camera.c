/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:17:17 by mploux            #+#    #+#             */
/*   Updated: 2017/08/04 20:14:44 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		is_collision(t_data *data, t_vec3 pos, t_vec2 dir)
{
	int x0;
	int x1;
	int z0;
	int z1;

	x0 = (int)floor(pos.x + dir.x - 0.3);
	x1 = (int)floor(pos.x + dir.x + 0.3);
	z0 = (int)floor(pos.z + dir.y - 0.3);
	z1 = (int)floor(pos.z + dir.y + 0.3);
	if (get_tile(data, x0, z0) != '0')
		return (1);
	if (get_tile(data, x1, z0) != '0')
		return (1);
	if (get_tile(data, x1, z1) != '0')
		return (1);
	if (get_tile(data, x0, z1) != '0')
		return (1);
	return (0);
}

static void		move_camera(t_data *data, double dx, double dz)
{
	t_vec3	pos;

	pos = data->cam_pos;
	if (!is_collision(data, pos, vec2(dx, 0)))
		data->cam_pos.x += dx;
	if (!is_collision(data, pos, vec2(0, dz)))
		data->cam_pos.z += dz;
}

void			manage_inputs(t_data *data, t_input *input)
{
	t_vec3			d;
	t_vec3			cd;
	double			a;

	d = vec3(0, 0, 0);
	cd = vec3(0, 0, 0);
	if (input->key[SDL_SCANCODE_W] || input->key[SDL_SCANCODE_UP])
		cd.z = 1;
	if (input->key[SDL_SCANCODE_S] || input->key[SDL_SCANCODE_DOWN])
		cd.z = -1;
	if (input->key[SDL_SCANCODE_A])
		cd.x = 1;
	if (input->key[SDL_SCANCODE_D])
		cd.x = -1;
	if (input->key[SDL_SCANCODE_LEFT])
		data->cam_angle -= 2;
	if (input->key[SDL_SCANCODE_RIGHT])
		data->cam_angle += 2;

	data->cam_angle += data->input->dx * 0.1;

	a = data->cam_angle;
	d.x += cd.x * sin(DTR(a)) + cd.z * cos(DTR(a));
	d.z += cd.z * sin(DTR(a)) - cd.x * cos(DTR(a));
	move_camera(data, d.x * 0.05, d.z * 0.05);
}
