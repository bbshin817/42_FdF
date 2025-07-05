/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:53:52 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/04 19:33:03 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_data;

// void	ft_mlx_pixel_put(t_data *img, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void draw()
// {
// 	void	*mlx;
// 	void	*mlx_window;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_window = mlx_new_window(mlx, 640, 480, "fdf");
// 	img.img = mlx_new_image(mlx, 640, 480);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	ft_mlx_pixel_put(&img, 320, 240, 0x00FF0000);
// 	ft_mlx_pixel_put(&img, 321, 240, 0x00FF0000);
// 	ft_mlx_pixel_put(&img, 322, 240, 0x00FF0000);
// 	ft_mlx_pixel_put(&img, 323, 240, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
// 	mlx_loop(mlx);

// 	return (1);
// }

void	coordinate_init(int fd)
{
	char	*line;
	char	**splitted;
	char	**tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;

	while ((line = get_next_line(fd)))
	{
		splitted = ft_split(line, ' ');
		tmp = splitted;
		while (*splitted)
		{
			isometric(x, y, ft_atoi(*splitted));
			free(*splitted);
			splitted++;
		}
		free(tmp);
		free(line);
	}
}

t_map map_init()
{
	t_map	map;

	map.width = 640;
	map.height = 480;
	map.zoom = 10;
	return (map);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd == -1)
		exit(-1);
	coordinate_init(fd);
	return (1);
}