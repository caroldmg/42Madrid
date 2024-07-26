/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:55:29 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/26 15:29:53 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_sqrt; ft_count_rotate

void ft_const_sort(t_node **a, t_node **b, int size)
{
	int	i;
	int	constant;
	
	i = 0;
	constant = ft_sqrt(size) * 1.4;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(&a, &b);
			if (ft_stack_size(b) > 1)
				rb(&b);
			i++;
		}
		else if ((*a)->index <= i + constant)
		{
			pb(&a, &b);
			i++;
		}
		else
			ra(&a);
	}
}

void common_sort(t_node **a, t_node **b, int size);
{
	int	rb_count;
	int	rrb_count;
	
	ft_const_sort(a, b, size);
	while (size - 1 >= 0)
	{
		
	}
}