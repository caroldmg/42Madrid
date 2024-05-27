/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:32:12 by cde-migu          #+#    #+#             */
/*   Updated: 2024/05/23 19:34:29 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void **swap(t_stack_node **stack)
{
	t_stack_node *aux;
	t_stack_node *first;

	if (stack == NULL || (*stack)->next == NULL )
		return ;
	first = *stack;
	aux = first;
	first = aux->next;
	aux->next = first->next;
	first->next = aux;
    stack = first;
	// añadir lo del prev?
}

void sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void sb(t_stack_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}