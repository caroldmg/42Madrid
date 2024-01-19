/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:20:05 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/14 18:21:09 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	isalpha;

	isalpha = 0;
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		isalpha = 1;
	return (isalpha);
}

/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%d", isalpha(65));
	printf("%d", ft_isalpha(65));
	return (0);
}
*/
