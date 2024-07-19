/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_midpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:20:27 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/19 11:56:32 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_node *stack)
{
	int	i;
	int	*arr;

	if (!stack)
		return (NULL);
	i = 0;
	arr = malloc(sizeof(int) * ft_stack_size(stack));
	if (!arr)
		return (NULL);
	while (stack)
	{
		arr[i] = stack->value;
		i++;
		stack = stack->next;
	}
	return (arr);
}

/* 
	DE MOMENTO PARA ORDENAR EL ARRAY VOY A USAR ESTE QUICKSORT,
	HAY QUE REVISAR OPTIMIZACIÓN
*/


static int ft_arrlen(int *arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static int	get_midpoint(int *arr)
{
	int mid;
	int len;

	len = ft_arrlen(arr);
	arr = quicksort(arr, 0, len -1);
	mid = arr[(len/2) - 1];
	return (mid);
}

int	is_less_midpoint(int *arr, int nb)
{
	return (nb < get_midpoint(arr));
}