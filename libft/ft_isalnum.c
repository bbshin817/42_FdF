/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:22:47 by sbaba             #+#    #+#             */
/*   Updated: 2024/07/06 17:20:18 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("[a], %d\n", ft_isalnum('a'));
// 	printf("[0], %d\n", ft_isalnum('0'));
// 	printf("[B], %d\n", ft_isalnum('B'));
// 	printf("[+], %d\n", ft_isalnum('+'));
// }