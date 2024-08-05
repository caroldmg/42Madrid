/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:21:58 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/05 16:56:06 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
//two elements
void	sort_two(t_node **a, t_node **b)
{
	show_stacks(a, b);
	if ((*a)->value > (*a)->next->value)
	{
		show_stacks(a, b);
		sa(a);
	}
}


//three elements
void	sort_three(t_node **a, t_node **b)
{
	t_node	*high;

	high = find_highest(*a);
	show_stacks(a, b);
	if (*a == high)
	{
		ra(a);
		show_stacks(a, b);	
	}
	else if ((*a)->next == high)
	{
		rra(a);
		show_stacks(a, b);
	}
	if ((*a)->value > (*a)->next->value)
	{
		sa(a);
		show_stacks(a, b);
	}
}

void	sort_four(t_node **a, t_node **b)
{
	t_node	*min;
	t_node	*current;

	min = *a;
	while (current->next)
	{
		if (current->index > min->index)
			min = current;
		current = current->next;
	}
	while ((*a) != min)
		ra(a);
	show_stacks(a, b);
	pb(a, b);
	show_stacks(a, b);
	sort_three(a, b);
	pa(a, b);
	show_stacks(a, b);
}

void	sort_five(t_node **a, t_node **b)
{
	t_node	*min;
	t_node	*current;

	min = *a;
	while (current->next)
	{
		if (current->index > min->index)
			min = current;
		current = current->next;
	}
	while ((*a) != min)
	{
		ra(a);
		show_stacks(a, b);
	}
	pb(a, b);
	show_stacks(a, b);
	sort_four(a, b);
	pa(a, b);
	show_stacks(a, b);
}
