/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:21:58 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/22 18:07:03 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static t_node	*find_highest(t_node *a)
{
	int				high;
	t_node	*high_node;
	
	if (!a)
		return (NULL);
	high = INT_MIN;
	while (a)
	{
		if (a->value > high)
		{
			high = a->value;
			high_node = a;
		}
		a = a->next;
	}
	return (high_node);
}

//three elements
void	sort_three(t_node **a)
{
	t_node	*high;

	high = find_highest(*a); //funcion para encontrar el mayor nodo de la lista
	if (*a == high)
		ra(a);
	else if ((*a)->next == high)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
