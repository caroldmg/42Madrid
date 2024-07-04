/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:21:58 by cde-migu          #+#    #+#             */
/*   Updated: 2024/06/12 12:25:21 by cde-migu         ###   ########.fr       */
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

t_stack_node	*find_highest(t_stack_node **a)
{
	t_stack_node *high;
	
	high = *a;
	while ((*a)->next)
	{
		if ((*a)->value > (*a)->next->value)
			high = *a;
		*a = (*a)->next;
	}
	return (high);
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

void	sort_four(t_stack_node **a)
{
	t_stack_node	**b;
	t_stack_node	*min;
	t_stack_node	*current;

	b = NULL;
	min = *a;
	while (current->next)
	{
		if (current->index > min->index)
			min = current;
		current = current->next;
	}
	while ((*a) != min)
		ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack_node **a)
{
	t_stack_node	**b;
	t_stack_node	*min;
	t_stack_node	*current;

	b = NULL;
	min = *a;
	while (current->next)
	{
		if (current->index > min->index)
			min = current;
		current = current->next;
	}
	while ((*a) != min)
		ra(a);
	pb(a, b);
	sort_four(a);
	pa(a, b);
}