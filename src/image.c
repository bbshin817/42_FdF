/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:00:21 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/06 21:48:54 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	view_image(t_img *img)
{
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->img, 0, 0);
	mlx_loop(img->mlx);
}

void	image_init(t_img *img, t_map map)
{
	img->mlx = NULL;
	img->mlx = mlx_init();
	img->mlx_window = mlx_new_window(img->mlx, map.window_width, map.window_height, "fdf");
	img->img = mlx_new_image(img->mlx, map.window_width, map.window_height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);

	return ;
}