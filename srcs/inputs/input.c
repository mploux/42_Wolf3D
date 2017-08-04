/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:14:30 by mploux            #+#    #+#             */
/*   Updated: 2017/08/04 20:13:41 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

t_input		*new_input(void)
{
	t_input	*input;
	int		i;

	if (!(input = (t_input *)ft_memalloc(sizeof(t_input))))
		error("malloc error !");
	i = -1;
	while (++i < KEY_SIZE)
		input->key[i] = 0;
	input->grabbed = 0;
	return (input);
}

void		handle_events(t_data *data, SDL_Event *event)
{
	if (event->type == SDL_QUIT || (event->type == SDL_KEYDOWN &&
		event->key.keysym.sym == SDLK_ESCAPE))
	{
		if (data->input->grabbed)
			data->input->grabbed = 0;
		else
			exit_wolf(data);
	}
	if (event->type == SDL_MOUSEMOTION)
	{
		data->input->x = event->motion.x;
		data->input->y = event->motion.y;
	}
	if (event->type == 	SDL_MOUSEBUTTONDOWN && event->button.button == 1)
		data->input->grabbed = 1;
	if (data->input->grabbed)
		SDL_ShowCursor(SDL_DISABLE);
	else
		SDL_ShowCursor(SDL_ENABLE);
	if (event->type == SDL_KEYDOWN)
		update_keys_down(event->key.keysym.scancode, data);
	if (event->type == SDL_KEYUP)
		update_keys_up(event->key.keysym.scancode, data);
}

void		update_keys_down(int key, t_data *data)
{
	if (key == SDL_SCANCODE_1)
		data->draw_mode = !data->draw_mode;
	if (key < KEY_SIZE)
		data->input->key[key] = 1;
}

void		update_keys_up(int key, t_data *data)
{
	if (key < KEY_SIZE)
		data->input->key[key] = 0;
}

int			get_key(t_input *input, int key)
{
	if (key < KEY_SIZE)
		return (input->key[key]);
	return (0);
}
