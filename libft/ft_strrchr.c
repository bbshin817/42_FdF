/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:59:49 by sbaba             #+#    #+#             */
/*   Updated: 2024/07/06 17:21:39 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*bs;
	const char	*ss;

	bs = (const char *)s;
	ss = NULL;
	while (*bs != '\0')
	{
		if (*bs == (char)c)
			ss = bs;
		++bs;
	}
	if ((char)c == '\0')
		return ((char *)bs);
	return ((char *)ss);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *result;
// 	char str[] = "abcdefghidjk";
// 	// int c = 'd';

// 	result = ft_strrchr(str, 'a');
// 	printf("The string found on %ld", result - str);
// }
