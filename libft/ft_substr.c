/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:43:54 by sbaba             #+#    #+#             */
/*   Updated: 2024/11/11 16:43:27 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	size_t	src_len;
	size_t	substr_len;
	char	*result;

	if (!src)
		return (NULL);
	src_len = ft_strlen(src);
	if (start > src_len)
	{
		result = (char *)malloc(sizeof(char));
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (start + len > src_len)
		substr_len = src_len - start;
	else
		substr_len = len;
	result = (char *)malloc((substr_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, (char *)(src + start), substr_len + 1);
	result[substr_len] = '\0';
	return (result);
}

// #include <stdio.h>

// int	main(){
// 	char str[] = "Hello, World!";
// 	int start = 1;
// 	size_t len = 5;

// 	char *result = ft_substr(str, start, len);
// 	if (result != NULL)
// 	{
// 		printf("Str: %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("failed!");
// 	}

// 	return (0);
// }