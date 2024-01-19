/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:17:25 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/16 11:15:57 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	while (dst[dst_len] != '\0')
		dst_len++;
	while (dst_len < dstsize - 1 && src[i] != '\0')
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	while (dst_len < dstsize)
	{
		dst[dst_len] = '\0';
		dst_len++;
	}
	return (ft_strlen(dst) + ft_strlen(src));
}

/*
#include <stdio.h>
#include <string.h>

int	main(void) {
	// Tamaño del búfer de destino
	unsigned long bufsize = 20;

	// Cadenas de prueba
	char dest1[20] = "Hola, ";
	char dest2[20] = "Hola, ";
	const char *src = "mundo!";

	// Llamada a ft_strlcat
	unsigned long result1 = ft_strlcat(dest1, src, bufsize);

	// Llamada a strlcat original
	unsigned long result2 = strlcat(dest2, src, bufsize);

	// Imprimir resultados
	printf("Resultado de ft_strlcat: %s (%lu)\n", dest1, result1);
	printf("Resultado de strlcat original: %s (%lu)\n", dest2, result2);

	// Comparar resultados
	if (strcmp(dest1, dest2) == 0 && result1 == result2) {
		printf("¡Las funciones coinciden!\n");
	} else {
		printf("¡Las funciones NO coinciden!\n");
	}

	return (0);
}
*/
/*
	gcc -c ft_strlen.c -o ft_strlen.o
	gcc -c ft_strlcat.c -o ft_strlcat.o

	gcc ft_strlen.o ft_strlcat.o -o myprogram
	./myprogram
*/