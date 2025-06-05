/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:49:16 by user              #+#    #+#             */
/*   Updated: 2024/11/11 16:43:44 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcat(char *dest, const char *src)
{
	size_t	destlen;
	size_t	srclen;
	int		i;

	destlen = 0;
	srclen = 0;
	i = 0;
	while (dest[destlen] != '\0')
		destlen++;
	while (src[i] != '\0')
	{
		dest[destlen] = src[i];
		destlen++;
		srclen++;
		i++;
	}
	dest[destlen] = '\0';
	return (destlen + srclen);
}

static size_t	ft_strcpy(char *dest, const char *src)
{
	size_t	i;
	size_t	strlen;

	i = 0;
	strlen = 0;
	while (src[strlen] != '\0')
		strlen++;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (strlen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		l1;
	size_t		l2;
	char		*result;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	result = (char *)malloc(l1 + l2 + 1);
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, s1);
	ft_strcat(result, s2);
	return (result);
}

// #include <stdio.h>

// int main()
// {
// 	const char s1[] = "Hello, ";
// 	const char s2[] = "World!";
// 	char *result = ft_strjoin(s1, s2);
// 	if(result != NULL){
// 		printf("Result: %s\n", result);
// 		free(result);
// 	}else{
// 		printf("failed!");
// 	}
// 	return (0);
// }