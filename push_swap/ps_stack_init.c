/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:24:36 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/04 13:19:17 by cde-migu         ###   ########.fr       */
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

// void stack_init(t_stack_node **a, char **argv)
// {
// 	int nbr;
	
	
// 	while (*argv)
// 	{
// 		// if (error_syntax(argv[i]))
// 		// 	error_free(a, argv);
// 		// 	//atol
// 		// nbr = ft_atoi(argv[i]);
// 		// if (nbr > INT_MAX || nbr < INT_MIN)
// 		// 	error_free(a, argv);
// 		// if (error_duplicate(*a, nbr))
// 		// 	error_free(a, argv);
// 		ft_new_node(a, nbr);
// 		argv++;
// 	}
// }

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