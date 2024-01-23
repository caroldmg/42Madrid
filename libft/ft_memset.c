/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:11:16 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/16 11:14:09 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			count;
	unsigned char	*ptr;

	ptr = b;
	count = 0;
	while (count < len)
	{
		*ptr = (unsigned char)c;
		count++;
		ptr++;
	}
	return (b);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    // Tamaño del array
    unsigned long size = 10;

    // Array para probar
    unsigned char originalArray[size];
    unsigned char customArray[size];

    // Valor a asignar
    int value = 65; // ASCII 'A'

    // Utiliza memset para inicializar originalArray
    memset(originalArray, value, size);

    // Utiliza ft_memset para inicializar customArray
    ft_memset(customArray, value, size);

    // Compara los resultados
    if (memcmp(originalArray, customArray, size) == 0) {
        printf("¡La función ft_memset funciona correctamente!\n");
    } else {
        printf("Hay un problema con la función ft_memset.\n");
    }

    return 0;
}
*/
