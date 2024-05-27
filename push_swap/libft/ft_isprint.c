/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:35:22 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/13 10:59:20 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}

/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%d", isprint(4));
	printf("%d", ft_isprint(4));
	return (0);
}
*/
