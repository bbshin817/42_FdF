/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:42:59 by sbaba             #+#    #+#             */
/*   Updated: 2024/11/06 17:57:54 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	f;
	size_t	s;

	f = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[f] != '\0' && f < len)
	{
		s = 0;
		while ((f + s) < len && big[f + s] == little[s] && little[s] != '\0')
			s++;
		if (little[s] == '\0')
			return ((char *)&big[f]);
		f++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <biging.h>

// int	main(void)
// {
// 	char	big[] = "";
// 	char	little[] = "";
// 	char	*result;

// 	printf("[bigings]\nbig: %s\nlittle: %s\n\n", big, little);
// 	result = ft_bigbig(big, little);
// 	// result = bigbig(big, little);
// 	printf("[Result]\npointer: %s\n", result);
// 	printf("Address: %p\n", result);
// }
