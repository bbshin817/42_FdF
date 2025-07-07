/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_inits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:19:10 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/07 17:24:03 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int count_spaces(char *str) //要修正！
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == ' ')
			i++;
		str++;
	}
	return (i);
}

int	expansion_coordinates_memory(t_coordinate ***coordinates, int height)
{
	t_coordinate	**tmp;

	tmp = *coordinates;
	*coordinates = malloc((height + 1) * sizeof(t_coordinate *));
	if (!*coordinates)
		return (-1);
	if (tmp)
	{
		ft_memcpy(*coordinates, tmp, sizeof(t_coordinate *) * height);
		free(tmp);
	}
	return (0);
}

void free_values(char *splitted, char **splitted_color)
{
	free(splitted);
	if (splitted_color[1])
		free(splitted_color[1]);
	free(splitted_color);
	return ;
}

int append(t_coordinate ***coordinates, char *line, int height)
{
	t_coordinate	coordinate;
	int				width;
	char			**splitted;
	char			**splitted_color;

	width = 0;
	splitted = ft_split(line, ' ');
	if (!splitted)
		return (-1);
	while (splitted[width])
	{
		splitted_color = ft_split(splitted[width], ',');
		if (!splitted_color)
			return (-1);
		coordinate.z = ft_atoi(splitted_color[0]);
		coordinate.color = 0xffffff;
		if (splitted_color[1])
			coordinate.color = hex_to_int(splitted_color[1]);
		(*coordinates)[height][width] = coordinate;
		free_values(splitted[width], splitted_color);
		// printf("Z: %d\n", (*coordinates)[height][width].z);
		width++;
	}
	free(splitted);
	return (0);
}

int	coordinate_init(int fd, t_map *map, t_coordinate ***coordinates)
{
	char	*line;

	while ((line = get_next_line(fd)))
	{
		if (expansion_coordinates_memory(coordinates, map->height) == -1)
			return (-1);
		map->width = (count_spaces(line) + 1);
		(*coordinates)[map->height] = malloc(map->width * sizeof(t_coordinate));
		if (!(*coordinates)[map->height] || append(coordinates, line, map->height) == -1)
		{
			free((*coordinates)[map->height]);
			free(line);
			return (-1);
		}
		free(line);
		map->height++;
	}
	return (0);
}
