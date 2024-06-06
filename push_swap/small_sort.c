/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:21:58 by cde-migu          #+#    #+#             */
/*   Updated: 2024/06/06 16:38:09 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

//two elements
void	sort_two(t_stack_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

//three elements
void	sort_three(t_stack_node **a)
{
	t_stack_node	*high;
	high = find_highest(*a); //funcion para encontrar el mayor nodo de la lista
	if (*a == high)
		ra(a);
	else if ((*a)->next == high)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}