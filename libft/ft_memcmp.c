/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:27:10 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/16 11:13:15 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pt_s1;
	unsigned char	*pt_s2;
	size_t			i;

	pt_s1 = (unsigned char *)s1;
	pt_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (pt_s1[i] != pt_s2[i])
			return (pt_s1[i] - pt_s2[i]);
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
    // Ejemplo de uso
    const char *str1 = "Hello";
    const char *str2 = "Hella";
    unsigned long n = strlen(str1);

    // Utilizando la función personalizada ft_memcmp
    int result_custom = ft_memcmp(str1, str2, n);

    // Utilizando la función estándar memcmp
    int result_standard = memcmp(str1, str2, n);

    // Comprobando los resultados
    if (result_custom == result_standard)
    {
        printf("La función ft_memcmp funciona correctamente.\n");
    }
    else
    {
        printf("Error: La función ft_memcmp no produce el mismo resultado que memcmp.\n");
    }

    return 0;
}
*/