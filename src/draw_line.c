/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:07:04 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/08 16:16:01 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	s_less(t_img *img, t_tilt tilt, t_coordinate start, t_coordinate end)
{
	t_line_pos	linepos;

	linepos.i = 0;
	linepos.p = 2 * abs(tilt.dy) - abs(tilt.dx);
	while (linepos.i <= abs(tilt.dx))
	{
		ft_mlx_pixel_put(img, start.x, start.y,
			line_clr(start.c, end.c, linepos.i, abs(tilt.dx)));
		if (tilt.dx > 0)
			start.x++;
		else
			start.x--;
		if (linepos.p < 0)
			linepos.p += 2 * abs(tilt.dy);
		else
		{
			if (tilt.dy > 0)
				start.y++;
			else
				start.y--;
			linepos.p += 2 * abs(tilt.dy) - 2 * abs(tilt.dx);
		}
		linepos.i++;
	}
	return ;
}

void	s_big(t_img *img, t_tilt t, t_coordinate s, t_coordinate e)
{
	t_line_pos	l;

	l.i = 0;
	l.p = 2 * abs(t.dx) - abs(t.dy);
	ft_mlx_pixel_put(img, s.x, s.y, s.c);
	while (l.i <= abs(t.dy))
	{
		ft_mlx_pixel_put(img, s.x, s.y, line_clr(s.c, e.c, l.i, abs(t.dy)));
		if (t.dy > 0)
			s.y++;
		else
			s.y--;
		if (l.p < 0)
			l.p += 2 * abs(t.dx);
		else
		{
			if (t.dx > 0)
				s.x++;
			else
				s.x--;
			l.p += 2 * abs(t.dx) - 2 * abs(t.dy);
		}
		l.i++;
	}
	return ;
}

void	draw_line(t_img *img, t_coordinate start, t_coordinate end)
{
	t_tilt	tilt;

	tilt.dx = end.x - start.x;
	tilt.dy = end.y - start.y;
	if (abs(tilt.dx) > abs(tilt.dy))
		s_less(img, tilt, start, end);
	else
		s_big(img, tilt, start, end);
	return ;
}

void	draw_map(t_img *img, t_map *map, t_coordinate ***coordinates)
{
	int	ix;
	int	iy;

	iy = 0;
	while (iy < map->height)
	{
		ix = 0;
		while (ix < map->width)
		{
			(*coordinates)[iy][ix].x += map->offset_x;
			(*coordinates)[iy][ix].y += map->offset_y;
			if (ix > 0)
				draw_line(img, (*coordinates)[iy][ix - 1],
					(*coordinates)[iy][ix]);
			if (iy > 0)
				draw_line(img, (*coordinates)[iy - 1][ix],
					(*coordinates)[iy][ix]);
			ix++;
		}
		iy++;
	}
	return ;
}
