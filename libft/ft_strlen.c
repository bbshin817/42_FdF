/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:22:20 by sbaba             #+#    #+#             */
/*   Updated: 2024/11/11 15:59:37 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const	char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *str = "Hello! World!";
// 	printf("String: %ld\n", ft_strlen(str));
// 	printf("%ld\n", strlen(str));

// 	return (0);
// }
