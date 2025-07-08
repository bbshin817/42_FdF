/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_inits_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:28:11 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/08 16:20:09 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	cpy_crds(t_coordinate ***dst, t_coordinate ***src, t_map *map, int h)
{
	int	ix;
	int	iy;

	iy = 0;
	while (iy < h)
	{
		(*dst)[iy] = malloc(map->width * sizeof(t_coordinate));
		if (!(*dst)[iy])
			return (-1);
		ix = 0;
		while (ix < map->width)
		{
			ft_memcpy(&(*dst)[iy][ix], &(*src)[iy][ix], sizeof(t_coordinate));
			ix++;
		}
		iy++;
	}
	return (0);
}
