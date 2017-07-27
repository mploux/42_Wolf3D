/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:57:52 by mploux            #+#    #+#             */
/*   Updated: 2017/07/27 18:58:56 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "wolf.h"
# include "maths.h"

typedef struct s_data		t_data;

typedef struct	s_bitmap
{
	t_data			*data;
	SDL_Renderer	*sdl_renderer;
	SDL_Texture		*sdl_texture;
	int				width;
	int				height;
	int				*pixels;
}				t_bitmap;

void			new_sdl_display(t_data *data, const char *title, int width,
																	int height);
void			sdl_loop(t_data *data, int (*loop)(t_data *));
void			draw_text(t_data *data, t_vec2 pos, int color, char *string);
void			draw_pix(t_data *data, double x, double y, int color);
void			draw_line(t_data *data, t_vec2 a, t_vec2 b, t_vec2 colors);
void			draw_line_x(t_data *data, t_vec2 a, t_vec2 b, t_vec2 colors);
void			draw_line_y(t_data *data, t_vec2 a, t_vec2 b, t_vec2 colors);
void			draw_quad(t_data *data, t_vec2 pos, t_vec2 size, int color);
void			draw_wall(t_data *data, t_vec2 p0, t_vec2 p1, int color);
t_bitmap		*new_bitmap(t_data *data, int width, int height);
void			bitmap_draw_pix(t_bitmap *b, int x, int y, int color);
void			bitmap_update(t_bitmap *b);
void			clear_bitmap(t_bitmap *b);
int				col_lerp(int a, int b, double n);
int				color(t_vec3 v);
int				color_angle(int angle, int sat);

#endif
