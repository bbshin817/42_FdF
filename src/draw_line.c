/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:07:04 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/06 23:42:00 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#include <stdio.h>

void	slope_less_than_one(t_img *img, int dx, int dy, t_coordinate coordinate)
{
	int p;
	int i;

	i = 0;
	p = 2 * abs(dy) - abs(dx);
	while (i <= abs(dx))
	{
		ft_mlx_pixel_put(img, coordinate.x, coordinate.y, 0xffffff);
		if (dx > 0)
			coordinate.x++;
		else
			coordinate.x--;
		if (p < 0)
			p += 2 * abs(dy);
		else
		{
			if (dy > 0)
				coordinate.y++;
			else
				coordinate.y--;
			p += 2 * abs(dy) - 2 * abs(dx);
		}
		i++;
	}
	return ;
}

void	slope_bigger_than_one(t_img *img, int dx, int dy, t_coordinate coordinate)
{
	int p;
	int i;

	i = 0;
	p = 2 * abs(dx) - abs(dy);
	ft_mlx_pixel_put(img, coordinate.x, coordinate.y, 0xffffff);
	while (i <= abs(dy))
	{
		ft_mlx_pixel_put(img, coordinate.x, coordinate.y, 0xffffff);
		if (dy > 0)
			coordinate.y++;
		else
			coordinate.y--;
		if (p < 0)
			p += 2 * abs(dx);
		else
		{
			if (dx > 0)
				coordinate.x++;
			else
				coordinate.x--;
			p += 2 * abs(dx) - 2 * abs(dy);
		}
		i++;
	}
	return ;
}

void	draw_line(t_img *img, t_coordinate start, t_coordinate end)
{
	int	dx;
	int	dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	if (abs(dx) > abs(dy))
		slope_less_than_one(img, dx, dy, start);
	else
		slope_bigger_than_one(img, dx, dy, start);
}

void	draw_map(t_img *img, t_map *map, t_coordinate ***coordinates)
{
	int ix;
	int iy;

	iy = 0;
	printf("window: %d x %d\n", map->window_width, map->window_height);
	while (iy < map->height)
	{
		ix = 0;
		while (ix < map->width)
		{
			(*coordinates)[iy][ix].x += map->window_width / 2;
			(*coordinates)[iy][ix].y += map->window_height / 2;
			printf("[%d] [%d, %d, %d]\n", (iy * map->width + ix), (*coordinates)[iy][ix].x, (*coordinates)[iy][ix].y, (*coordinates)[iy][ix].z);

			(void)img;
			// if (ix < map->width - 1)
			// 	draw_line(img, (*coordinates)[iy][ix], (*coordinates)[iy][ix + 1]);
			// if (iy < map->height - 1)
			// 	draw_line(img, (*coordinates)[iy][ix], (*coordinates)[iy + 1][ix]);
			ix++;
		}
		iy++;
	}
}