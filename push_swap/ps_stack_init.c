/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:24:36 by cde-migu          #+#    #+#             */
/*   Updated: 2024/05/28 13:43:33 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void stack_init(t_stack_node **a, char **argv)
// {
// 	int nbr;
// 	int i;
	
// 	i = 0;
// 	while (*argv)
// 	{
// 		if (error_syntax(argv[i]))
// 			error_free(a, argv);
// 		//atol
// 		nbr = ft_atoi(argv[i]);
// 		if (nbr > INT_MAX || nbr < INT_MIN)
// 			error_free(a, argv);
// 		if (error_duplicate(*a, nbr))
// 			error_free(a, argv);
// 		ft_node_addback(a, nbr);
// 		argv++;
// 	}
// }

// void ft_node_addback(t_stack_node **stack, int nbr)
// {
// 	t_stack_node *new;
// 	t_stack_node *last;
// 	if (!stack)
// 		return ;
// 	new = malloc(sizeof(t_stack_node));
// 	if (!new)
// 		return ;
// 	new->next = NULL;
// 	new->value = nbr;
// 	if (!*stack)
// 	{
// 		*stack = new;
// 		new->prev = NULL;
// 	}
// 	else
// 	{
// 		last = ft_get_last_node(*stack);
// 		last->next = new;
// 	}
// }

// static int	error_syntax(char *a)
// {
// 	int i;
	
// 	i = 0;
// 	if (a[i] == '+' || a[i] == '-')
// 		i++;
// 	while (a[i])
// 	{
// 		if (!ft_isdigit(a[i]))
// 		{
// 			write(1, "Error\n", 6);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// static int error_duplicate(t_stack_node *a, int nbr)
// {
// 	if (!a)
// 		return (0);
// 	while (a)
// 	{
// 		if (a->value == nbr)
// 		{
// 			write(1, "Error\n", 6);
// 			return (1);
// 		}
// 		a = a->next;
// 	}
// 	return (0);
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