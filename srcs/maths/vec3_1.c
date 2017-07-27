/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:27:37 by mploux            #+#    #+#             */
/*   Updated: 2017/01/05 08:52:06 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

double		vec3_mag(t_vec3 a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vec3		vec3_mul(t_vec3 a, t_vec3 b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	return (a);
}

t_vec3		vec3_mul_d(t_vec3 a, double d)
{
	a.x *= d;
	a.y *= d;
	a.z *= d;
	return (a);
}

t_vec3		vec3_clamp(t_vec3 v, double min, double max)
{
	t_vec3 result;

	result.x = clamp(v.x, min, max);
	result.y = clamp(v.y, min, max);
	result.z = clamp(v.z, min, max);
	return (result);
}

t_vec3		vec3_reflect(t_vec3 dir, t_vec3 normal)
{
	t_vec3	result;
	double	dot;

	dot = vec3_dot(dir, normal);
	result = vec3_sub(dir, vec3_mul_d(normal, dot * 2.0));
	return (result);
}
