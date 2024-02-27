/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:17:38 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/16 13:12:33 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_putnbr_fd(int n, int fd)
// {
// 	if (n == -2147483648)
// 	{
// 		ft_putstr_fd("-2147483648", fd);
// 	}
// 	else
// 	{
// 		if (n < 0)
// 		{
// 			ft_putchar_fd('-', fd);
// 			n = n * -1;
// 		}
// 		if (n > 9)
// 		{
// 			ft_putnbr_fd(n / 10, fd);
// 		}
// 		ft_putchar_fd(n % 10 + '0', fd);
// 	}
// }

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	if (str)
		ft_putstr_fd(str, fd);
	free(str);
}
/*
int main(void)
{
	ft_putnbr_fd("-2147483648", 1);
	return (0);
}
*/