/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:53:52 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/08 15:56:28 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	map_init(void)
{
	t_map	map;

	map.window_width = 640;
	map.window_height = 480;
	map.width = 0;
	map.height = 0;
	map.zoom = 6;
	return (map);
}

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
	if (coordinate_set(fd, &map, &coordinates) == -1)
	{
		free_coordinates(&coordinates, map.height);
		exit(-1);
	}
	init_positions(&map, &coordinates);
	image_init(&img, map);
	draw_map(&img, &map, &coordinates);
	free_coordinates(&coordinates, map.height);
	view_image(&img);
	close_mlx(&img);
	return (0);
}
