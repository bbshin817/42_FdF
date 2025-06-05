/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:01:26 by sbaba             #+#    #+#             */
/*   Updated: 2024/11/12 15:39:54 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*bs;

	bs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		bs[i] = c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	// char	str[] = "Hello, World!";
// 	size_t	len = 13;
// 	// ft_memset(str, '\0', len);
// 	// memset(NULL, '\0', len);
// 	// printf("After memset: %s", str);
// }
