/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:17:47 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/15 12:55:02 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str)
{
	if (!(*str == '+'
			|| *str == '-'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+'
			|| *str == '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_all(t_stack_node **stack, char **argv)
{
	t_stack_node	*aux;
	t_stack_node	*current;
	
	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		aux = current->next;
		free(current);
		current = aux;
	}
	*stack = NULL;
	write(2, "Error\n", 6);
}