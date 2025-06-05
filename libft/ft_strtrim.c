/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:21:37 by sbaba             #+#    #+#             */
/*   Updated: 2024/11/11 16:44:06 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	search_by_front(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t	search_by_back(const char *s1, const char *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (0 < i && ft_strchr(set, s1[i - 1]))
		i--;
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	front;
	size_t	back;
	size_t	len;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	front = search_by_front(s1, set);
	back = search_by_back(s1, set);
	if (front >= back)
		len = 0;
	else
		len = back - front;
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, (char *)(s1 + front), len + 1);
	result[len] = '\0';
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s1[] = "     The     Taco Rice  ! !   ";
// 	char set[] = " ";

// 	printf("s1: %s\nset: %s\n", s1, set);
// 	printf("Result: %s", ft_strtrim(s1, set));
// }
