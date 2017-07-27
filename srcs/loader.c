/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 06:21:14 by mploux            #+#    #+#             */
/*   Updated: 2017/01/05 17:58:04 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <unistd.h>
#include <fcntl.h>

static int		read_line_cells(t_data *data, char *line)
{
	int			x;
	char		**toks;

	x = 0;
	toks = NULL;
	toks = ft_strsplit(line, ' ');
	if (!toks || !toks[0])
		error("loader error: invalid map !");
	while (toks[x])
	{
		ft_lstadd(&data->m_list, ft_lstnew(toks[x], sizeof(char)));
		free(toks[x]);
		x++;
	}
	free(toks);
	return (x);
}

static int		load_cells(t_data *data, const int fd, t_vec2 *s)
{
	char		*line;
	t_vec2		pos;
	int			nx;
	int			ret;

	pos.x = 0;
	pos.y = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		nx = read_line_cells(data, line);
		if (pos.y != 0 && pos.x != nx)
			error("loader error: map not aligned !");
		pos.x = nx;
		pos.y++;
		ft_strdel(&line);
	}
	if (pos.x + pos.y == 0)
		error("loader error: invalid map !");
	if (ret < 0)
		return (error("loader error: invalid file !"));
	s->x = pos.x;
	s->y = pos.y;
	return (1);
}

void			load_map(t_data *data, char *file)
{
	int			fd;
	int			i;
	int			index;
	int			size;
	t_vec3		pos;

	pos = vec3(0, 0, 0);
	fd = open(file, O_RDONLY);
	load_cells(data, fd, &data->size);
	size = data->size.x * data->size.y;
	if (!(data->map = (char *)ft_memalloc(sizeof(char) * size)))
		error("malloc error !");
	i = -1;
	while (++i < size)
	{
		index = size - i - 1;
		data->map[i] = *((char *)(ft_lstget(data->m_list, index)->content));
		if (data->map[i] == '9')
			pos = vec3(i % (int)data->size.x, 0, i / (int)data->size.x);
	}
	data->cam_pos = pos;
	close(fd);
	ft_lstclear(&data->m_list);
}

void			load_colors(t_data *data, char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	**toks;
	t_vec3	col;

	i = -1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0 && ++i < 5)
	{
		toks = ft_strsplit(line, ' ');
		if (!toks[0] || !toks[1] || !toks[2] || toks[3])
			error("color error: invalid color format !");
		col = vec3(ft_atoi(toks[0]), ft_atoi(toks[1]), ft_atoi(toks[2]));
		data->colors[i] = col;
		free(toks[0]);
		free(toks[1]);
		free(toks[2]);
		free(toks);
		free(line);
	}
	line = NULL;
	close(fd);
}
