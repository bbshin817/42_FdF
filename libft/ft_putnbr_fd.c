/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:59:00 by user              #+#    #+#             */
/*   Updated: 2024/11/10 20:09:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		digit = '0' + (n % 10);
		write(fd, &digit, 1);
	}
}

// void	ft_putnbr_fd(int n, int fd)
// {
// 	unsigned int	i;

// 	if (n < 0)
// 	{
// 		ft_putchar_fd('-', fd);
// 		i = -n;
// 	}
// 	else
// 	{
// 		i = n;
// 	}
// 	if (i >= 10)
// 		ft_putnbr_fd(i / 10, fd);
// 	ft_putchar_fd((i % 10) + '0', fd);
// }