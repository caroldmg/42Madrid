/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:55:29 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/05 16:08:57 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_sqrt; ft_count_rotate

static int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 4)
		return (1);
	i = 2;
	while (i * i <= nb)
		i++;
	return (i - 1);
}

static void ft_const_sort(t_node **a, t_node **b, int size)
{
	int	i;
	int	constant;
	
	i = 0;
	constant = ft_sqrt(size) * 1.4;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			if (ft_stack_size(*b) > 1)
				rb(b);
			i++;
		}
		else if ((*a)->index <= i + constant)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
		show_stacks(a, b);
	}
}

static int ft_count_rotate(t_node *stack, int max)
{
	int c;

	c = 0;
	while (stack && stack->index != max)
	{
		stack = stack->next;
		c++;
	}
	return (c);
}

void common_sort(t_node **a, t_node **b, int size)
{
	int	rb_count;
	int	rrb_count;
	
	ft_const_sort(a, b, size);
	while (size - 1 >= 0)
	{
		rb_count = ft_count_rotate(*b, size - 1);
		rrb_count = size - rb_count;
		if (rb_count <= rrb_count)
		{
			while ((*b)->index != size - 1)
				rb(b);
			pa(a, b);
			size--;
		}
		else
		{
			while ((*b)->index != size - 1)
				rrb(b);
			pa(a, b);
			size--;
		}
		show_stacks(a, b);
	}
}