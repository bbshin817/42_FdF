/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:06:16 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/08 16:20:52 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_ext_strlen(const	char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static size_t	ft_ext_strcat(char *dest, const char *src)
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

static size_t	ft_ext_strcpy(char *dest, const char *src)
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

char	*ft_ext_strjoin(char *s1, char *s2)
{
	char	*result;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	result = (char *)malloc(ft_ext_strlen(s1) + ft_ext_strlen(s2) + 1);
	if (result == NULL)
		return (NULL);
	ft_ext_strcpy(result, s1);
	ft_ext_strcat(result, s2);
	free(s1);
	return (result);
}
