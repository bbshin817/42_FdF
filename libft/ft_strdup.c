/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:44:01 by sbaba             #+#    #+#             */
/*   Updated: 2024/11/09 23:02:48 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	return (ft_substr(s, 0, ft_strlen(s)));
}

// #include <stdio.h>

// int main(void)
// {
// 	char	*src = "Hello, World!";
// 	char	*dest;

// 	dest = ft_strdup(src);
// 	printf("Copied Value: %s", dest);
// }
