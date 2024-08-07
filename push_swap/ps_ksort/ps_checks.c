/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:12:35 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/07 17:26:00 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_node **stack)
{
	t_node	*aux;
	t_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		aux = current->next;
		//current->value = NULL;
		free(current);
		current = aux;
	}
	*stack = NULL;
}

void	handle_error(t_node **a)
{
	free_all(a);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_check_value(char *value)
{
	if (!(*value == '+'
			|| *value == '-'
			|| ft_isdigit(*value)))
		return (1);
	if ((*value == '+'
			|| *value == '-') && ! ft_isdigit(value[1]))
		return (1);
	while (*++value)
	{
		if (!ft_isdigit(*value))
			return (1);
	}
	return (0);
}

int	ft_check_repeat(t_node *stack, int nb)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}
