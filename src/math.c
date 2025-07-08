/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:25:17 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/08 15:56:52 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	isometric(int *x, int *y, int z)
{
	int	tmp;

	tmp = *x;
	*x = (tmp - *y) * cos(0.523599);
	*y = (tmp + *y) * sin(0.523599) - z;
}

int	hex_to_int(char *hex)
{
	int	result;
	int	value;

	result = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		hex += 2;
	while (*hex)
	{
		if (*hex >= '0' && *hex <= '9')
			value = *hex - '0';
		else if (*hex >= 'A' && *hex <= 'F')
			value = *hex - 'A' + 10;
		else if (*hex >= 'a' && *hex <= 'f')
			value = *hex - 'a' + 10;
		else
			break ;
		result = result * 16 + value;
		hex++;
	}
	return (result);
}
