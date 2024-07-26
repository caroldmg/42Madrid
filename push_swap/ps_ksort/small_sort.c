/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:21:58 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/26 15:06:47 by cde-migu         ###   ########.fr       */
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
void	sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
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

void	sort_four(t_node **a)
{
	t_node	**b;
	t_node	*min;
	t_node	*current;

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

void	sort_five(t_node **a)
{
	t_node	**b;
	t_node	*min;
	t_node	*current;

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