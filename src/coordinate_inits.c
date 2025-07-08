/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_inits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:19:10 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/08 16:18:07 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	count_value(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*str)
	{
		if (*str != ' ')
		{
			if (flag == 0)
				i++;
			flag = 1;
		}
		else
			flag = 0;
		str++;
	}
	return (i);
}

int	expand_memory(t_coordinate ***coordinates, int height, t_map *map)
{
	t_coordinate	**tmp;

	tmp = *coordinates;
	*coordinates = malloc((height + 1) * sizeof(t_coordinate *));
	if (!*coordinates)
		return (-1);
	if (tmp)
	{
		if (cpy_crds(coordinates, &tmp, map, height) == -1)
			return (-1);
		free_coordinates(&tmp, height);
	}
	return (0);
}

int	append(t_coordinate ***coordinates, char *line, t_map *map)
{
	t_coordinate	coordinate;
	int				width;
	char			**splitted;
	char			**splitted_color;

	width = 0;
	splitted = ft_split(line, ' ');
	if (!splitted)
		return (-1);
	while (splitted[width] && width < map->width)
	{
		splitted_color = ft_split(splitted[width], ',');
		if (!splitted_color)
			return (-1);
		coordinate.z = ft_atoi(splitted_color[0]);
		coordinate.c = 0xffffff;
		if (splitted_color[1])
			coordinate.c = hex_to_int(splitted_color[1]);
		(*coordinates)[map->height][width] = coordinate;
		free_splitted(splitted_color);
		width++;
	}
	free_splitted(splitted);
	return (0);
}

int	coordinate_set(int fd, t_map *map, t_coordinate ***coordinates)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (expand_memory(coordinates, map->height, map) == -1)
			return (-1);
		if (0 == map->width)
			map->width = count_value(line);
		(*coordinates)[map->height] = malloc(map->width * sizeof(t_coordinate));
		if (!(*coordinates)[map->height]
			|| append(coordinates, line, map) == -1)
		{
			free((*coordinates)[map->height]);
			free(line);
			return (-1);
		}
		free(line);
		map->height++;
		line = get_next_line(fd);
	}
	return (0);
}
