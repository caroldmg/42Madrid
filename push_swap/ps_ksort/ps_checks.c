/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:12:35 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/12 17:05:18 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_len(char *nums)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (nums[i] == '+' || nums[i] == '-')
		i++;
	while (nums[i] == '0')
		i++;
	while (nums[i])
	{
		i++;
		count++;
	}
	if (count >= 11)
		return (0);
	return (1);
}

void	ft_check_value(char **argv, t_node **a)
{
	int	i;
	int	j;
	int	nums;

	i = 1;
	j = 0;
	nums = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			handle_error(a);
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
			&& (argv[i][j] != '-') && (argv[i][j] != '+'))
				handle_error(a);
			if (ft_isdigit(argv[i][j]))
				nums++;
			j++;
		}
		if (nums == 0)
			handle_error(a);
		j = 0;
		nums = 0;
		i++;
	}
}

void	ft_check_repeat(t_node **stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack)
		return ;
	current = *stack;
	while (current->next)
	{
		temp = current->next;
		while (temp)
		{
			if (current->value == temp->value)
				handle_error(stack);
			temp = temp->next;
		}
		current = current->next;
	}
}

static int	ft_check_overflow(char *nb)
{
	if (!ft_check_len(nb) || (ft_atoi(nb) != ft_atol(nb)))
		return (0);
	return (1);
}

int	ft_nums_ok(char **nums)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nums[i])
	{
		while (nums[i][j])
		{
			if (!(ft_isdigit(nums[i][j + 1])) && (nums[i][j + 1]))
				return (0);
			j++;
		}
		j = 0;
		if (!ft_check_overflow(nums[i]))
			return (0);
		i++;
	}
	return (1);
}
