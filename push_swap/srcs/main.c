/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:06:53 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/16 12:35:45 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (free_all(&a, 0), 0);
	push_swap(&a, &b);
	free_all(&a, 0);
	return (0);
}
