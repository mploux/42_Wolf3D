/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:27:37 by mploux            #+#    #+#             */
/*   Updated: 2016/12/15 20:14:36 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

t_vec4		vec4(double x, double y, double z, double w)
{
	t_vec4 v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}

t_vec4		vec2_2(t_vec2 a, t_vec2 b)
{
	t_vec4 v;

	v.x = a.x;
	v.y = a.y;
	v.z = b.x;
	v.w = b.y;
	return (v);
}
