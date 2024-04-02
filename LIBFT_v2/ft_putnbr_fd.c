/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:17:38 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/29 21:07:46 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa(n);
	if (str)
		i = ft_putstr_fd(str, fd);
	free(str);
	return (i);
}

/* int main(void)
{
	int res = ft_putnbr_fd(42332, 1);
	printf("\n ------- \n");
	printf("res = %i \n ", res);
	return (0);
} */
