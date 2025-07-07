/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:07:04 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/07 15:57:53 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	slope_less_than_one(t_img *img, int dx, int dy, t_coordinate start, t_coordinate end)
{
	int p;
	int i;

	i = 0;
	p = 2 * abs(dy) - abs(dx);
	while (i <= abs(dx))
	{
		ft_mlx_pixel_put(img, start.x, start.y, interpolate_color(start.color, end.color, i, abs(dx)));
		if (dx > 0)
			start.x++;
		else
			start.x--;
		if (p < 0)
			p += 2 * abs(dy);
		else
		{
			if (dy > 0)
				start.y++;
			else
				start.y--;
			p += 2 * abs(dy) - 2 * abs(dx);
		}
		i++;
	}
	return ;
}

void	slope_bigger_than_one(t_img *img, int dx, int dy, t_coordinate start, t_coordinate end)
{
	int p;
	int i;

	i = 0;
	p = 2 * abs(dx) - abs(dy);
	ft_mlx_pixel_put(img, start.x, start.y, start.color);
	while (i <= abs(dy))
	{
		ft_mlx_pixel_put(img, start.x, start.y, interpolate_color(start.color, end.color, i, abs(dy)));
		if (dy > 0)
			start.y++;
		else
			start.y--;
		if (p < 0)
			p += 2 * abs(dx);
		else
		{
			if (dx > 0)
				start.x++;
			else
				start.x--;
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
		slope_less_than_one(img, dx, dy, start, end);
	else
		slope_bigger_than_one(img, dx, dy, start, end);
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
			(*coordinates)[iy][ix].x += map->offset_x;
			(*coordinates)[iy][ix].y += map->offset_y;
			if (ix > 0)
				draw_line(img, (*coordinates)[iy][ix - 1], (*coordinates)[iy][ix]);
			if (iy > 0)
				draw_line(img, (*coordinates)[iy - 1][ix], (*coordinates)[iy][ix]);
			ix++;
		}
		iy++;
	}
}