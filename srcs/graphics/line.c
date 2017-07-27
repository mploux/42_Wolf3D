/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:44:10 by mploux            #+#    #+#             */
/*   Updated: 2016/12/20 15:16:21 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	draw_line_x(t_data *data, t_vec2 a, t_vec2 b, t_vec2 colors)
{
	t_vec2	pos;
	double	n;
	double	nx;

	pos.x = -1;
	pos.y = a.y;
	while (++pos.x < ABS(b.x - a.x))
	{
		n = pos.x / ABS(b.x - a.x);
		pos.y = LERP(a.y, b.y, n);
		nx = a.x + pos.x * (b.x - a.x < 0 ? -1 : 1);
		draw_pix(data, (int)(nx), (int)pos.y, col_lerp(colors.x, colors.y, n));
	}
}

void	draw_line_y(t_data *data, t_vec2 a, t_vec2 b, t_vec2 colors)
{
	t_vec2	pos;
	double	n;
	double	ny;

	pos.x = a.x;
	pos.y = -1;
	while (++pos.y < ABS(b.y - a.y))
	{
		n = pos.y / ABS(b.y - a.y);
		pos.x = LERP(a.x, b.x, n);
		ny = a.y + pos.y * (b.y - a.y < 0 ? -1 : 1);
		draw_pix(data, (int)pos.x, (int)(ny), col_lerp(colors.x, colors.y, n));
	}
}
