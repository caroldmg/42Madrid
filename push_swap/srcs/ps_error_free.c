/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:26:58 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/14 13:30:29 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_all(t_node **stack, int error_flag)
{
	t_node	*aux;
	t_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		aux = current->next;
		current->value = 0;
		free(current);
		current = aux;
	}
	if (error_flag)
		free(stack);
	*stack = NULL;
}

void	handle_error(t_node **a)
{
	if (a)
		free_all(a, 0);
	error_msg();
}

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
