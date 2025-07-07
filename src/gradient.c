/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:07:04 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/07 14:43:49 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	fraction(float x1, float x2, float x)
{
	if (x1 != x2)
		return ((x - x1) / (x2 - x1));
	return (0);
}

int	interpolate_color(int start, int end, int num, int den)
{
	int	r;
	int	g;
	int	b;

	if (start == end)
		return (start);
	r = ((start >> 16 & 0xFF)
			+ (((end >> 16 & 0xFF)
					- (start >> 16 & 0xFF)) * num) / den);
	g = ((start >> 8 & 0xFF)
			+ (((end >> 8 & 0xFF)
					- (start >> 8 & 0xFF)) * num) / den);
	b = ((start & 0xFF)
			+ (((end & 0xFF)
					- (start & 0xFF)) * num) / den);
	return ((r << 16) | (g << 8) | b);
}
