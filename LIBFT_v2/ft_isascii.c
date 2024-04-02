/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:27:59 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/27 12:46:20 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}

/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%d", isascii(138));
	printf("%d", ft_isascii(138));
	return (0);
}
*/