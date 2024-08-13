/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:21:58 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/13 19:23:02 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_highest(t_node *a)
{
	int		high;
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

void	sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_node **a)
{
	t_node	*high;

	high = find_highest(*a);
	if (*a == high)
		ra(a);
	else if ((*a)->next == high)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_four(t_node **a, t_node **b)
{
	t_node	*min;
	t_node	*current;

	min = *a;
	current = *a;
	while (current)
	{
		if (current->index < min->index)
			min = current;
		current = current->next;
	}
	while ((*a) != min)
		ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	if (!stack_sorted(*a))
		ra(a);
}

void	sort_five(t_node **a, t_node **b)
{
	small_sort_helper(a);
	pb(a, b);
	small_sort_helper(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}


void	small_sort_helper(t_node **a)
{
	t_node	*min;
	t_node	*current;
	int i;

	min = *a;
	current = *a;
	i = 0;
	while (current)
	{
		if (current->index < min->index)
			min = current;
		current = current->next;
	}
	current = *a;
	while (current && current != min) {
		i++;
		current = current->next;
	}
	while ((*a) != min) {
		if (i > 2)	
			rra(a);
		else
			ra(a);
	}
}
