/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_inits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:19:10 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/06 20:52:35 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int count_spaces(char *str)
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

int	coordinate_init(int fd, t_map *map, t_coordinate ***coordinates)
{
	t_coordinate	coordinate;
	char			*line;
	char			**splitted;
	char			**tmp;

	while ((line = get_next_line(fd)))
	{
		if (expansion_coordinates_memory(coordinates, map->height) == -1)
			return (-1);
		map->width = (count_spaces(line) + 1);
		(*coordinates)[map->height] = malloc(map->width * sizeof(t_coordinate));
		if (!(*coordinates)[map->height])
			return (-1);
		splitted = ft_split(line, ' ');
		tmp = splitted;
		map->width = 0;
		while (splitted[map->width])
		{
			coordinate.z = ft_atoi(splitted[map->width]);
			(*coordinates)[map->height][map->width] = coordinate;
			free(splitted[map->width]);
			map->width++;
		}
		free(tmp);
		free(line);
		map->height++;
	}
	return (0);
}
