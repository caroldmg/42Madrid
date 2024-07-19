/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:30:56 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/19 12:16:40 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	common_sort_a(t_node **a, t_node **b)
{
	while (ft_stack_size(&a) > 3)
	{
		int *arr;

		arr = stack_to_array(&a);
		if (is_less_midpoint(arr, (*a)->value))
			pb(&a, &b);
		else if (is_less_midpoint(arr, ft_get_last_node(*a)))
		{
			rra(&a);
			pb(&a, &b);
		}
		else
		{
			ra(&a);
			common_sort(&a, &b);
		}
	}
	return (&a, &b);
}

void	push_swap(t_node **a)
{
	t_node	*b;
		//cuidado, si lo hago recursivo voy a perder todos lols valores de B
	b = NULL;
	common_sort(&a, &b);
}
