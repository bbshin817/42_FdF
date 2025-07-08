/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_inits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:21:24 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/08 16:10:03 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_size	size_init(void)
{
	t_size	size;

	size.min_x = INT_MAX;
	size.min_y = INT_MAX;
	size.max_x = INT_MIN;
	size.max_y = INT_MIN;
	return (size);
}

void	check_size(t_size *size, int x, int y)
{
	if (x < size->min_x)
		size->min_x = x;
	if (x > size->max_x)
		size->max_x = x;
	if (y < size->min_y)
		size->min_y = y;
	if (y > size->max_y)
		size->max_y = y;
	return ;
}

void	set_window_size(t_map *map, t_size size)
{
	map->window_width = size.max_x - size.min_x;
	map->window_height = size.max_y - size.min_y;
	map->window_width += map->window_width / 2;
	map->window_height += map->window_height / 2;
	map->offset_x = map->window_width / 2;
	map->offset_y = map->window_height / 2;
	map->offset_x -= (size.max_x + size.min_x) / 2;
	map->offset_y -= (size.max_y + size.min_y) / 2;
	return ;
}

void	init_positions(t_map *map, t_coordinate ***coordinates)
{
	int		ix;
	int		iy;
	int		x;
	int		y;
	t_size	size;

	size = size_init();
	iy = 0;
	while (iy < map->height)
	{
		ix = 0;
		while (ix < map->width)
		{
			x = ix * map->zoom + map->window_width / 2;
			y = iy * map->zoom + map->window_height / 2;
			isometric(&x, &y, (*coordinates)[iy][ix].z * map->zoom);
			check_size(&size, x, y);
			(*coordinates)[iy][ix].x = x;
			(*coordinates)[iy][ix].y = y;
			ix++;
		}
		iy++;
	}
	set_window_size(map, size);
	return ;
}
