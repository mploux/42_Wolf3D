/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:07:42 by mploux            #+#    #+#             */
/*   Updated: 2017/01/05 17:59:19 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				get_tile(t_data *data, double x, double y)
{
	int xx;
	int yy;
	int tile;

	xx = (int)(x);
	yy = (int)(y);
	if (xx < 0 || yy < 0 || xx >= data->size.x || yy >= data->size.y)
		return ('0');
	tile = data->map[(int)(xx + yy * data->size.x)];
	if (tile == '9')
		return ('0');
	return (tile);
}
