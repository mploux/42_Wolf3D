/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 21:12:02 by mploux            #+#    #+#             */
/*   Updated: 2017/01/05 18:01:53 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_vec2		calc_delta(t_vec2 dir)
{
	t_vec2 result;

	result.x = sqrt(1 + (dir.y * dir.y) / (dir.x * dir.x));
	result.y = sqrt(1 + (dir.x * dir.x) / (dir.y * dir.y));
	return (result);
}

t_vec2		calc_side_dist(t_vec2 delta, t_vec3 pos, t_vec2 dir)
{
	t_vec2 result;
	t_vec2 ipos;

	ipos = vec2(floor(pos.x), floor(pos.z));
	if (dir.x < 0)
		result.x = (pos.x - ipos.x) * delta.x;
	else
		result.x = (ipos.x + 1 - pos.x) * delta.x;
	if (dir.y < 0)
		result.y = (pos.z - ipos.y) * delta.y;
	else
		result.y = (ipos.y + 1 - pos.z) * delta.y;
	return (result);
}

void		calc_ray_hit(t_data *data, t_ray *ray)
{
	int		i;
	int		tile;

	i = -1;
	tile = 0;
	while ((tile = get_tile(data, ray->map.x, ray->map.y)) == '0' && ++i < 999)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta.x;
			ray->map.x += ray->step.x;
			ray->axis = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta.y;
			ray->map.y += ray->step.y;
			ray->axis = 1;
		}
	}
	if (tile != '0' && tile != '9')
		ray->color = data->colors[tile - '0' - 1];
}

void		ray_hit_dist(t_ray *ray)
{
	double xdiff;
	double ydiff;

	xdiff = ray->map.x - ray->pos.x;
	ydiff = ray->map.y - ray->pos.z;
	if (ray->axis == 0)
		ray->dist = (xdiff + (1.0 - ray->step.x) / 2.0) / ray->dir.x;
	else
		ray->dist = (ydiff + (1.0 - ray->step.y) / 2.0) / ray->dir.y;
}

t_ray		throw_ray(t_data *data, t_vec3 pos, t_vec2 dir)
{
	t_ray	result;
	t_vec3	color;

	result.pos = pos;
	result.dir = dir;
	result.map = vec2(floor(pos.x), floor(pos.z));
	result.delta = calc_delta(dir);
	result.side_dist = calc_side_dist(result.delta, pos, dir);
	result.step = vec2(dir.x < 0 ? -1 : 1, dir.y < 0 ? -1 : 1);
	calc_ray_hit(data, &result);
	ray_hit_dist(&result);
	if (data->draw_mode == 0)
	{
		if (result.axis)
			color = result.step.y < 0 ? data->colors[0] : data->colors[1];
		else
			color = result.step.x < 0 ? data->colors[2] : data->colors[3];
	}
	else
		color = vec3_mul_d(result.color, result.axis * 0.4 + 0.6);
	result.color = color;
	return (result);
}
