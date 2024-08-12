/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:06:53 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/12 10:40:21 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO delete
void	show_stacks(t_node **a, t_node **b)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = *a;
	node_b = *b;
	printf("╭───────╥───────╮\n│   a\t║   b\t│\n╞═══════╬═══════╡\n");
	while (node_a || node_b)
	{
		if (node_a)
		{
			printf("│ %i\t║", node_a->index);
			node_a = node_a->next;
		}
		else
			printf("│\t║");
		if (node_b)
		{
			printf(" %i\t│\n", node_b->index);
			node_b = node_b->next;
		}
		else
			printf("\t│\n");
	}
	printf("╰───────╨───────╯\n");
}

// int	main(int argc, char **argv)
// {
// 	t_node	*a;
// 	t_node	*b;

// 	a = NULL;
// 	b = NULL;
// 	if (argc == 1 || (argc == 2 && !argv[1][0]))
// 		return (1);
// 	else if (argc == 2)
// 		argv = ft_split(argv[1], ' ');
// 	stack_init(&a, argv + 1);
// 	if (stack_sorted(a))
// 	{
// 		printf("stack is sorted!!");
// 		return (0);
// 	}
// 	push_swap(&a, &b);
// 	free_all(&a);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc >= 2)
		a = stack_init(argv, &a);
	if (stack_sorted(a))
		return (free_all(&a), 0);
	push_swap(&a, &b);
	free_all(&a);
	return (0);
}
