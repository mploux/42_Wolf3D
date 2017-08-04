/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:27:37 by mploux            #+#    #+#             */
/*   Updated: 2017/08/04 18:36:51 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

t_vec3		vec3_lerp(t_vec3 a, t_vec3 b, double fog)
{
	t_vec3	result;

	result.x = LERP(a.x, b.x, fog);
	result.y = LERP(a.y, b.y, fog);
	result.z = LERP(a.z, b.z, fog);
	return (result);
}
