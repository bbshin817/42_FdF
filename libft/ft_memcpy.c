/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:29:57 by sbaba             #+#    #+#             */
/*   Updated: 2024/10/22 01:51:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	d = (char *)dst;
	s = (const char *)src;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	dst[20];
// 	char	src[] = "hello, world!";

// 	printf("[Before]\n");
// 	printf("dst: %s\nsrc: %s\n\n", dst, src);
// 	ft_memcpy(dst, src, 1);
// 	printf("[After]\n");
// 	printf("dst: %s\nsrc: %s\n\n", dst, src);
// }
