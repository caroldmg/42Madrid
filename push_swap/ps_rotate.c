/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:53:33 by cde-migu          #+#    #+#             */
/*   Updated: 2024/05/28 13:45:46 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*aux;

	current = ft_get_last_node(*stack);
	aux = NULL;
	if (!stack || !*stack || ft_stack_size(*stack) <= 1)
		return ;
	while (current->prev != NULL)
	{
		aux = current->prev;
		aux->next = current;
		current = aux;
	}
	if (current->prev == NULL)
	{
		current->prev = ft_get_last_node(*stack);
		current->next = NULL;
	}
}

// static void rotate2(t_stack_node **stack)
// {
// 	t_stack_node *last;

// 	if (stack == NULL || *stack == NULL)
// 		return ;
// 	last = ft_get_last_node(*stack);
// 	last->next = *stack;
// 	*stack = (*stack)->next;
// 	(*stack)->prev = NULL;
// 	last->next->prev = last;
// 	last->next->next = NULL;
// }

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}