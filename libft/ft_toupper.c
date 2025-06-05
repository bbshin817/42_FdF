/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:31:20 by sbaba             #+#    #+#             */
/*   Updated: 2024/11/11 16:56:36 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	str[] = {'l', 'q', 'D', '!', '4'};

// 	for(int i=0; i<5; i++){
// 		printf("[input]\n%c\n[output]\n%c\n\n", str[i], ft_toupper(str[i]));
// 	}
// }
