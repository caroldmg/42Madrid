/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:55:29 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/16 15:38:02 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int len_a;
	int len_b;

	len_a = ft_stack_size(a);
	len_b = ft_stack_size(b);

	while (b)
	{
		b->cost = b->index;
	}
}