/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:34:03 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/16 11:12:47 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*pt_s;
	size_t	        i;

	ch = (unsigned char)c;
	pt_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (pt_s[i] == ch)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    const char *str = "Hello, World!";
    int search_char = 'o';
    unsigned long n = strlen(str);

    // Utilizando la función personalizada ft_memchr
    void *result_custom = ft_memchr(str, search_char, n);

    // Utilizando la función estándar memchr
    void *result_standard = memchr(str, search_char, n);

    // Comprobando los resultados
    if (result_custom == result_standard)
    {
        printf("La función ft_memchr funciona correctamente.\n");
    }
    else
    {
        printf("Error: La función ft_memchr no produce el mismo resultado que memchr.\n");
    }

    return 0;
}
*/