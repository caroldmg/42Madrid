/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:12:35 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/22 18:02:51 by cde-migu         ###   ########.fr       */
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
		free(current);
		current = aux;
	}
	*stack = NULL;
	write(2, "Error\n", 6);
}


int ft_check_value(char *value)
{
	int	i;

	i = 0;
	if (!(value[i] == '+'
			|| value[i] == '-'
			|| ft_isdigit(value[i])))
		return (1);
	if ((value[i] == '+'
		|| value[i] == '-') && ! ft_isdigit(value[i + 1]))
		return (1);
	while (value[++i])
	{
		if (!ft_isdigit(value[i]))
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
