/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:24:36 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/13 17:21:40 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	i = 0;
	sign = 1;
	while (str[i] && (str[i] == ' '
			|| (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (!ft_isdigit(str[i + 1]))
			return (nbr * sign);
		i++;
	}
	return (1);
}

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

// void	ft_add_stack(char *str, t_node **a)
// {
// 	char	**str_array;
// 	int		i;
// 	long	nb;

// 	i = 0;
// 	str_array = ft_split(str, ' ');
// 	while (str_array[i])
// 	{
// 		if (ft_check_value(str_array[i]))
// 			ft_free_split(&str_array[i], i);
// 		nb = ft_atol(str_array[i]);
// 		if (nb > INT_MAX || nb < INT_MIN)
//  			handle_error(a);
// 		if (ft_check_repeat(*a, (int)nb))
// 			ft_free_split(str_array, i);
// 		ft_new_node(a, (int)nb);
// 		free(str_array[i++]);
// 	}
// 	free(str_array);
// }

// t_node	*stack_init(char **argv, t_node **a)
// {
// 	int		i;

// 	i = 1;
// 	while (argv[i])
// 		ft_add_stack(argv[i++], a);
// 	return (*a);
// }

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
			error_msg();;
		}
		else
		{
			while (numbers[j])
			{
				ft_new_node(stack, ft_atoi(numbers[j]));
				j++;
			}
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
