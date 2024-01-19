/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:40:31 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/14 18:21:40 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	int	isdigit;

	isdigit = 0;
	if (c >= 48 && c <= 57)
		isdigit = 1;
	return (isdigit);
}

/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%d", isdigit(50));
	printf("%d", ft_isdigit(50));
	return (0);
}
*/
