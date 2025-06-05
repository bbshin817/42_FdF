/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:52:39 by sbaba             #+#    #+#             */
/*   Updated: 2024/10/22 02:07:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*copy_with_overlap(char *d, const char *s, size_t n, int b)
{
	size_t	i;

	if (b)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (0 < i)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (d);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;

	if (dest == src)
		return (dest);
	d = (char *)dest;
	s = (const char *)src;
	copy_with_overlap(d, s, n, d < s);
	return (dest);
}
