/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:07:04 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/08 16:13:32 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	line_clr(int start, int end, int num, int den)
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
