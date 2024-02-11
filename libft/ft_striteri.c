/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:41:15 by cde-migu          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/03 18:02:19 by cde-migu         ###   ########.fr       */
=======
/*   Updated: 2024/02/03 13:47:51 by cde-migu         ###   ########.fr       */
>>>>>>> f27ee2fde4bf4fbaac39d1f42304152f660d6fad
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
=======
void ft_striteri(char *s, void (*f)(unsigned int, char*))
>>>>>>> f27ee2fde4bf4fbaac39d1f42304152f660d6fad
{
	unsigned int	count;

	if (!s || !f)
		return ;
	count = 0;
	while (*s)
	{
		f(count, s);
		s++;
		count++;
	}
}
