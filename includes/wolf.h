/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:10:33 by mploux            #+#    #+#             */
/*   Updated: 2017/07/27 19:44:34 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <SDL.h>
# include <stdlib.h>
# include <string.h>
# include "input.h"
# include "libft.h"
# include "maths.h"
# include "graphics.h"
# include "input.h"
# include <stdio.h>
# include <pthread.h>

typedef struct s_mesh		t_mesh;
typedef struct s_bitmap		t_bitmap;
typedef struct s_input		t_input;

typedef struct	s_win
{
	void		*ctx;
	int			w;
	int			h;
	char		*name;
}				t_win;

typedef struct	s_ray
{
	t_vec3		pos;
	t_vec2		dir;
	double		dist;
	int			axis;
	t_vec2		map;
	t_vec2		delta;
	t_vec2		side_dist;
	t_vec2		step;
	t_vec3		color;
}				t_ray;

typedef struct	s_thread
{
	pthread_t	id;
	t_data		*data;
	int			x;
	int			width;
}				t_thread;

typedef struct	s_data
{
	SDL_Window	*sdl_win;
	SDL_Surface	*sdl_surface;
	int			thread_num;
	t_thread	*threads;
	t_win		*win;
	t_input		*input;
	t_bitmap	*framebuffer;
	t_list		*m_list;
	char		*map;
	t_vec2		size;
	t_vec3		cam_pos;
	t_vec3		spawn;
	t_vec2		cam_rot;
	int			cam_angle;
	int			draw_mode;
	t_vec3		colors[5];
}				t_data;

int				error(char *error);
int				create_wolf(t_data *data, const char *name, int width,
																	int height);
void			loop_wolf(t_data *data);
void			exit_wolf(t_data *data);
void			load_map(t_data *data, char *file);
void			load_colors(t_data *data, char *file);
void			draw_scene(t_data *data);
void			manage_inputs(t_data *data, t_input *input);
int				get_tile(t_data *data, double x, double y);
t_ray			throw_ray(t_data *data, t_vec3 pos, t_vec2 dir);
void			draw_minimap(t_data *data);
int				close_request(t_data *data);

#endif
