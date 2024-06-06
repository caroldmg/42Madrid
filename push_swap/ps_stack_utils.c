/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:37:55 by cde-migu          #+#    #+#             */
/*   Updated: 2024/05/28 13:41:45 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *ft_get_last_node(t_stack_node *stack)
{
	t_stack_node *last;
	
	last = stack;
	if (stack == NULL)
		return (NULL);
	while (last -> next)
		last = last->next;
	return (last);
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

t_stack_node	*ft_new_node(int nb)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (0);
	node->value = nb;
	node->next = NULL;
	return (node);
}