/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:00:21 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/08 16:03:23 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_close(int keycode, t_img *img)
{
	if (keycode != 65307)
		return (-1);
	mlx_loop_end(img->mlx);
	return (0);
}

int	window_close(t_img *img)
{
	mlx_loop_end(img->mlx);
	return (0);
}

void	view_image(t_img *img)
{
	mlx_hook(img->mlx_window, 2, (1L << 0), key_close, img);
	mlx_hook(img->mlx_window, 17, 0L, window_close, img);
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->img, 0, 0);
	mlx_loop(img->mlx);
	return ;
}

void	image_init(t_img *img, t_map map)
{
	img->mlx = NULL;
	img->mlx = mlx_init();
	img->mlx_window = mlx_new_window(img->mlx,
			map.window_width, map.window_height, "fdf");
	img->img = mlx_new_image(img->mlx, map.window_width, map.window_height);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	return ;
}
