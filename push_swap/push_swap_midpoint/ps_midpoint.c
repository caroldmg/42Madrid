/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_midpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:20:27 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/26 12:14:01 by cde-migu         ###   ########.fr       */
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
	arr = malloc(sizeof(int) * (ft_stack_size(stack) + 1));
	if (!arr)
		return (NULL);
	while (stack)
	{
		arr[i] = stack->value;
		i++;
		stack = stack->next;
	}
	arr[i] = '\0';
	return (arr);
}

int	ft_len_to_midpoint(int *arr)
{
	int len;
	int mid;
	
	len = 0;
	mid = get_midpoint(arr);
	while (arr[len] != mid)
		len++;
	return (len);
}
/* 
	DE MOMENTO PARA ORDENAR EL ARRAY VOY A USAR ESTE QUICKSORT,
	HAY QUE REVISAR OPTIMIZACIÓN
*/

int ft_arrlen(int *arr)
{
	int i;
	
	if (!arr)
		return(0);
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