/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:13:18 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/15 16:05:04 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	int				len;

	len = ft_stack_size(*stack);
	if (!stack || !*stack || len == 1)
		return ;
	last = ft_get_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}
void rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 3);
}

void rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 3);
}

void rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 3);
}
