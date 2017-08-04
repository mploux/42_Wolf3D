/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:33:37 by mploux            #+#    #+#             */
/*   Updated: 2017/08/04 19:45:51 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "wolf.h"

# define KEY_SIZE 1024

typedef struct s_data	t_data;

typedef struct	s_input
{
	int			key[KEY_SIZE];
	int			button;
	int			x;
	int			y;
	double		dx;
	double		dy;
	int			lx;
	int			ly;
	int			grabbed;
}				t_input;

t_input			*new_input();
void			handle_events(t_data *data, SDL_Event *event);
void			update_keys_down(int key, t_data *data);
void			update_keys_up(int key, t_data *data);
int				get_key(t_input *input, int key);
void			update_mouse(t_data *data);

#endif
