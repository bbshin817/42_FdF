/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:53:52 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/06 22:59:58 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map map_init()
{
	t_map	map;

	map.window_width = 640;
	map.window_height = 480;
	map.width = 0;
	map.height = 0;
	map.zoom = 15;
	return (map);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int				fd;
	t_map			map;
	t_coordinate	**coordinates;
	t_img			img;

	coordinates = NULL;
	map = map_init();
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd == -1)
		exit(-1);
	coordinate_init(fd, &map, &coordinates);
	init_positions(&map, &coordinates);
	image_init(&img, map);
	draw_map(&img, &map, &coordinates);
	view_image(&img);
	return (1);
}