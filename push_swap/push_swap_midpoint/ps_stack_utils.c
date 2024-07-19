/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:37:55 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/17 12:38:56 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *ft_get_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack -> next)
		stack = stack->next;
	return (stack);
}

int	ft_stack_size(t_node *stack)
{
	int size;

	size = 0;
	if (!stack)
		return (size);
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	ft_new_node(t_node **stack, int nb)
{
	t_node	*node;
	t_node	*last;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nb;
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
