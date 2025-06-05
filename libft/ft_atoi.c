/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:01:23 by sbaba             #+#    #+#             */
/*   Updated: 2024/12/09 15:53:43 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
31: the absolute value of long min is one greater than
	long max, so we add one directly to it.
*/

static long	consideration_overflow(char *str, int sign)
{
	unsigned long	result;
	unsigned long	over;
	int				digit;

	result = 0;
	digit = 0;
	over = (unsigned long)LONG_MAX;
	while ('0' <= *str && *str <= '9')
	{
		digit = *str - '0';
		if (0 < result && sign == 1 && result > (over - digit) / 10)
			return (LONG_MAX);
		if (0 < result && sign == -1 && result > (over - digit + 1) / 10)
			return (LONG_MIN);
		result = result * 10 + digit;
		str++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (((9 <= *str && *str <= 13) || *str == 32) && *str != '\0')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	result = (int)consideration_overflow((char *)str, sign);
	return (result * sign);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char *argv[])
// {
// 	printf("[Input]\n%s\n\n[Result]\nft_atoi: %d\n", argv[1], ft_atoi(argv[1]));
// 	printf("atoi: %d", atoi(argv[1]));
// }
