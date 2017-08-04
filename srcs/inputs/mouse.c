/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 19:15:54 by mploux            #+#    #+#             */
/*   Updated: 2017/08/04 20:19:20 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	update_mouse(t_data *data)
{
	data->input->dx = (data->input->x - data->win->w / 2) * 0.5;
	data->input->dy = (data->input->y - data->win->h / 2) * 0.5;
	SDL_WarpMouseInWindow(data->sdl_win, data->win->w / 2, data->win->h / 2);
}
