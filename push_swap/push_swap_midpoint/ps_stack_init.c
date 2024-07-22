/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:24:36 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/22 18:03:38 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// //añadir un indice a los elementos

// static int	add_index(t_stack_node **a, t_stack_node *current)
// {
// 	int				index;
	
// 	index = 0;
// 	while ((*a)->next != NULL)
// 	{
// 		if ((*a)->value > current->value)
// 			index++;
// 		*a = (*a)->next;
// 	}
// 	current->index = index;
// 	return (index);
// }

static long	ft_atol(const char *str)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	i = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;	
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - 0;
		i++;
	}
	return (nbr * sign);
}

void stack_init(t_node **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_check_value(argv[i]))
			free_all(a);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_all(a);
		if (error_duplicate(*a, nbr))
			free_all(a);
		ft_new_node(a, nbr);
		++i;
	}
}

// int main(void)
// {
// 	t_stack_node *a;
// 	a = NULL;
	
// 	char *args[] = {args[0] = "\0", args[1] = "34", args[2] = "3456", args[3] = "12", args[4] = NULL};
// 	stack_init(&a, args+1);
// 	while (a)
// 	{
// 		printf("\n%d, node with address %p \n", a->value, a);
// 		a = a->next;
// 	}
// 	return (0);
// }