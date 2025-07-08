/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:55:13 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/08 16:36:31 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

typedef struct s_map
{
	int	window_width;
	int	window_height;
	int	offset_x;
	int	offset_y;
	int	width;
	int	height;
	int	zoom;
}	t_map;

typedef struct s_img
{
	void	*mlx;
	void	*mlx_window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_coordinate
{
	int	x;
	int	y;
	int	z;
	int	c;
}	t_coordinate;

typedef struct s_size
{
	int	max_x;
	int	min_x;
	int	max_y;
	int	min_y;
}	t_size;

typedef struct s_tilt
{
	int	dx;
	int	dy;
}	t_tilt;

typedef struct s_line_pos
{
	int	p;
	int	i;
}	t_line_pos;

int		coordinate_set(int fd, t_map *map, t_coordinate ***coordinates);
void	init_positions(t_map *map, t_coordinate ***coordinates);
void	isometric(int *x, int *y, int z);
void	image_init(t_img *img, t_map map);
void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_map(t_img *img, t_map *map, t_coordinate ***coordinates);
void	view_image(t_img *img);
int		hex_to_int(char *hex);
int		line_clr(int start, int end, int num, int den);
int		cpy_crds(t_coordinate ***dst, t_coordinate ***src, t_map *map, int h);
void	free_splitted(char **splitted);
void	free_coordinates(t_coordinate ***coordinates, int height);
void	close_mlx(t_img *img);

#endif