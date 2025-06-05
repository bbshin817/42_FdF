/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:31:17 by sbaba             #+#    #+#             */
/*   Updated: 2024/11/11 16:56:14 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	str[] = {'A', 'c', 'D', '!', '4'};

// 	for(int i=0; i<5; i++){
// 		printf("[input]\n%c\n[output]\n%c\n\n", str[i], ft_tolower(str[i]));
// 	}
// }
