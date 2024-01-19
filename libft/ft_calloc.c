/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:54:28 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/16 11:09:26 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr != 0)
		ft_memset(ptr, 0, count * size);
	return (ptr);
}

/*
#include <stdio.h>
int main()
{
    const size_t size = 5;

    // Usando tu función calloc
    int *arr1 = (int *)ft_calloc(size, sizeof(int));
    if (arr1 == NULL)
    {
        fprintf(stderr, "Error al asignar memoria con tu función calloc.\n");
        return EXIT_FAILURE;
    }

    // Llenar arr1 con algunos valores
    for (size_t i = 0; i < size; ++i)
    {
        arr1[i] = i + 1;
    }

    // Usando la función calloc de la biblioteca estándar
    int *arr2 = (int *)calloc(size, sizeof(int));
    if (arr2 == NULL)
    {
        fprintf(stderr, "Error al asignar memoria con la función calloc de la biblioteca estándar.\n");
        free(arr1);  // Liberar la memoria asignada por tu función calloc antes de salir
        return EXIT_FAILURE;
    }

    // Llenar arr2 con algunos valores
    for (size_t i = 0; i < size; ++i)
    {
        arr2[i] = i + 1;
    }

    // Comparar ambos arreglos
    if (ft_memcpy(arr1, arr2, size * sizeof(int)) != arr1)
    {
        fprintf(stderr, "Error: Los arreglos no son iguales.\n");
        free(arr1);
        free(arr2);
        return EXIT_FAILURE;
    }

    // Imprimir los resultados
    printf("Arreglo asignado por tu función calloc:\n");
    for (size_t i = 0; i < size; ++i)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Arreglo asignado por la función calloc de la biblioteca estándar:\n");
    for (size_t i = 0; i < size; ++i)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Liberar la memoria asignada
    free(arr1);
    free(arr2);

    return EXIT_SUCCESS;
}
*/

/*
gcc -c ft_memset.c -o ft_memset.o
gcc -c ft_memcpy.c -o ft_memcpy.o
gcc -c ft_calloc.c -o ft_calloc.o

gcc ft_memset.o ft_memcpy.o ft_calloc.o -o my_program

./my_program
*/