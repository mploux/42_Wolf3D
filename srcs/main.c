/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:07:59 by mploux            #+#    #+#             */
/*   Updated: 2017/07/27 18:53:38 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "graphics.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		close_request(t_data *data)
{
	exit_wolf(data);
	return (0);
}

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2 && ac != 3)
		error("usage: wolf map_file [color_file]");
	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		error("malloc error !");
	create_wolf(data, "Wolf3D !", 1920, 1080);
	if (ac == 3)
		load_colors(data, av[2]);
	load_map(data, av[1]);
	loop_wolf(data);
	return (0);
}
