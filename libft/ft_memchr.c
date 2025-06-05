/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:33:33 by sbaba             #+#    #+#             */
/*   Updated: 2024/11/11 17:06:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t				i;
	const unsigned char	*p;

	i = 0;
	p = b;
	while (i < len)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}

// void	*ft_memchr(const void *s, int c, size_t n)
// {
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	while (i < n)
// 	{
// 		if (*(unsigned char *)(s + i) == (unsigned char)c)
// 			return ((void *)(s + i));
// 		i++;
// 	}
// 	return (NULL);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "Hello, World!";
// 	char	*result = ft_memchr(str, 'W', 13);

// 	if (result != NULL)
// 		printf("Found 'W' at position: %ld\n", (result - str));
// 	else
// 		printf("Character 'W' not found.\n");
// }
