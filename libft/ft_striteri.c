/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:58:53 by user              #+#    #+#             */
/*   Updated: 2024/11/11 16:42:02 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// void	fnc(unsigned int i, char *str)
// {
// 	printf("%d", str[i]);
// }

// int	main(){
// 	void	(*f)(unsigned int, char*) = fnc;
// 	char *str = "hello, world";

// 	ft_striteri(str, f);
// }