/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:46:40 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/26 12:44:18 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	MY_POWER
	Esta función calcula (2^n) donde n es el argumento pasado a la función. 
	Utiliza un bucle for para multiplicar nbr por 2, n veces.
	Al inicio, nbr se establece en 1, y después del bucle, nbr será igual a (2^n).
*/

static int	my_power(int n)
{
	int	i;
	int	nbr;

	nbr = 1;
	for (i = 0; i < n; ++i)
		nbr *= 2;
	return (nbr);
}

/*
	Esta función busca el exponente más pequeño x 
	tal que (2^x \geq n), donde n es el número proporcionado como argumento. 
	Comienza con x = 0 y aumenta x hasta que (2^x) sea mayor o igual a n. 
	Utiliza la función my_power 
	para calcular las potencias de 2.
*/

static int	find_npower(int n)
{
	int	x;

	x = 0;
	while (n > my_power(x)) {
		x++;
	}
	return (x);
}

/*
Esta función crea un arreglo dinámico de enteros.
utiliza find_npower para determinar el tamaño del arreglo 
necesario basándose en el número de elementos que se desea almacenar.
Luego, asigna memoria para el arreglo utilizando malloc,
reservando espacio para n + 2 enteros,
donde n es el valor retornado por find_npower.
*/

int	*ft_get_num_chunks(int len)
{
	int	n;
	int	*arr;

	n = find_npower(len);
	arr = (int*)malloc(sizeof(int) * n + 2);
	return (arr);
}

void	sort_chunk(t_node *a, t_node *b, int len)
{
	
}