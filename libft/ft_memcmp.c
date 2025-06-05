/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:10:19 by sbaba             #+#    #+#             */
/*   Updated: 2024/07/06 17:21:39 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*b1;
	const unsigned char	*b2;

	b1 = (const unsigned char *)s1;
	b2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (b1[i] != b2[i])
			return (b1[i] - b2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	p1[] = "abcfef1133";
// 	char	p2[] = "abcdee11";
// 	printf("[Result]\n%d", ft_memcmp(p1, p2, 4));
// }