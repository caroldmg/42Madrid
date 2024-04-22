/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:24:06 by cde-migu          #+#    #+#             */
/*   Updated: 2024/04/18 17:34:52 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrbase_fd(size_t nbr, char *base, int fd)
{
	int	len;
	int	result;

	result = 0;
	len = ft_strlen(base);
	if (nbr >= (size_t)len)
		result += ft_putnbrbase_fd(nbr / len, base, fd);
	result += ft_putchar_fd(base[nbr % len], fd);
	return (result);
}

/* int main(void)
{
	int res = ft_putnbrbase_fd(42, "01", 1);
	printf("\n ------- \n");
	printf("res = %i \n ", res);
	return (0);
} */