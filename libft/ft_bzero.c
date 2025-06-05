/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:01:56 by sbaba             #+#    #+#             */
/*   Updated: 2024/11/10 20:09:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			t;

	p = (unsigned char *)s;
	t = 0;
	while (t < n)
	{
		p[t] = '\0';
		t++;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	size_t n = 10;
// 	void *result = malloc(n);

// 	ft_bzero(result, n);

// 	printf("[Address]\n%p\n", result);
// 	free(result);
// }