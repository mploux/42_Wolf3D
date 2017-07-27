/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:23:22 by mploux            #+#    #+#             */
/*   Updated: 2017/01/05 06:33:45 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int		col_lerp(int a, int b, double n)
{
	t_vec3 ca;
	t_vec3 cb;
	t_vec3 cl;

	ca.x = (int)((a & 0xff0000) >> 16);
	ca.y = (int)((a & 0xff00) >> 8);
	ca.z = (int)((a & 0xff));
	cb.x = (int)((b & 0xff0000) >> 16);
	cb.y = (int)((b & 0xff00) >> 8);
	cb.z = (int)((b & 0xff));
	cl.x = LERP(ca.x, cb.x, n);
	cl.y = LERP(ca.y, cb.y, n);
	cl.z = LERP(ca.z, cb.z, n);
	return ((int)cl.x << 16 | (int)cl.y << 8 | (int)cl.z);
}

int		color_angle(int angle, int sat)
{
	t_vec3	col;

	col.x = clamp(balance(0, 255, angle) - sat, 0, 255);
	col.y = clamp(balance(0, 255, angle + 127) - sat, 0, 255);
	col.z = clamp(balance(0, 255, angle + 255) - sat, 0, 255);
	return ((int)col.x << 16 | (int)col.y << 8 | (int)col.z);
}

int		color(t_vec3 v)
{
	return ((int)v.x << 16 | (int)v.y << 8 | (int)v.z);
}
