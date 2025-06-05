/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:41:40 by sbaba             #+#    #+#             */
/*   Updated: 2024/11/06 17:52:43 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	int		i;

	destlen = 0;
	while (dest[destlen] != '\0' && destlen < size)
		destlen++;
	srclen = ft_strlen(src);
	if (size <= destlen)
		return (srclen + size);
	i = 0;
	while (src[i] != '\0' && destlen + i < size - 1)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}

// #include <stdio.h>
// #include <string.h> 
// int	main(void)
// {
// 	char	dest[] = "Hong";
// 	char	src[] = "Kong";
// 	printf("[Strings]\ndest: \"%s\"\nsrc: \"%s\"\n\n", dest, src);
// 	printf("[Result]\nft_strcat(): %zu\n", ft_strlcat(dest, src, 8));
// 	printf("dest: %s", dest);
// }
