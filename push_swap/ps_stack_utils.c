/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:37:55 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/04 13:20:12 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *ft_get_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack -> next)
		stack = stack->next;
	return (stack);
}

int	ft_stack_size(t_stack_node *stack)
{
	int size;
	t_stack_node *current;

	size = 0;
	current = stack;
	while (current->next)
	{
		current = current->next;
		size++;
	}
	return (size);
}

void	ft_new_node(t_stack_node **stack, int nb)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->value = nb;
	node->next = NULL;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = ft_get_last_node(*stack);
		last->next = node;
		node->prev = last;
	}
}
