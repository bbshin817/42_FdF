/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:24:07 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/08 15:43:22 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void free_coordinates(t_coordinate ***coordinates, int height)
{
	int i = 0;
	while (i < height)
	{
		free((*coordinates)[i]);
		i++;
	}
	free(*coordinates);
	return ;
}

void free_splitted(char **splitted)
{
	int	i;

	i = 0;
	if (!splitted)
		return;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}