/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:24:36 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/16 12:40:02 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_split(char **argv, t_node **stack)
{
	char	**numbers;
	int		i;
	int		j;

	i = 1;
	j = 0;
	numbers = NULL;
	while (argv[i])
	{
		j = 0;
		numbers = ft_split(argv[i], ' ');
		if (!ft_nums_ok(numbers))
		{
			ft_free_split(numbers);
			error_msg();
		}
		else
		{
			while (numbers[j])
				ft_new_node(stack, ft_atoi(numbers[j++]));
			ft_free_split(numbers);
		}
		i++;
	}
}

t_node	*stack_init(char **argv, t_node **a)
{
	ft_check_value(argv, a);
	ft_check_split(argv, a);
	ft_check_repeat(a);
	return (*a);
}
