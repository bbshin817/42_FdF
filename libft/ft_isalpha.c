/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:42:26 by sbaba             #+#    #+#             */
/*   Updated: 2024/11/10 20:30:58 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("[a], %d\n", ft_isalpha('a'));
// 	printf("[0], %d\n", ft_isalpha('0'));
// 	printf("[C], %d\n", ft_isalpha('C'));
// 	printf("[+], %d\n", ft_isalpha('+'));
// }