/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:38:44 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/22 18:04:37 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char ** argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_stack_init(&a, argv + 1);
	if (!is_sorted(a))
	{
		if (ft_stack_size(a) == 2)
			sa(&a);
		else if (ft_stack_size(a) == 3)
			sort_three(&a);
		else
		//algoritmo tocho de ordenacion
			push_swap(&a, &b);
	}
	free_all(&a);
}
