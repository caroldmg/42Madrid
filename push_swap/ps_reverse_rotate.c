/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:13:18 by cde-migu          #+#    #+#             */
/*   Updated: 2024/05/27 15:22:41 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(t_stack_node **stack)
{
	t_stack_node *aux;

	if (stack == NULL || *stack == NULL)
		return ;
	aux = (*stack)->next;
	*stack = ft_get_last_node(*stack);
	aux->prev = NULL;
	(*stack)->next = NULL;
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
