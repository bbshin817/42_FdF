/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:49:09 by sbaba             #+#    #+#             */
/*   Updated: 2024/11/06 17:51:20 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str1[] = "Hello, World!";
// 	char	str2[] = "HellO, World!";
// 	printf("[Input Strings]\nstr1: \"%s\"\nstr2: \"%s\"\n", str1, str2);
// 	printf("[Result]\nft_strcmp(): %d\n", ft_strncmp(str1, str2, 3));
// 	printf("strcmp(): %d\n", strncmp(str1, str2, 3));
// }