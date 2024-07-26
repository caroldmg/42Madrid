/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:30:56 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/26 12:43:12 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	common_sort_a(t_node **a, t_node **b)
{
	int	*num_chunks;
	int *arr;
	int	count;
	int	i;

	i = 0;
	num_chunks = ft_get_num_chunks(ft_stack_size(a));
	while (ft_stack_size(&a) > 0)
	{
		count = 0;
		arr = stack_to_array(&a);
		while (count < ft_len_to_midpoint(arr))
		{	
			if (is_less_midpoint(arr, (*a)->value))
			{
				pb(&a, &b);
				count++;	
			}
			else if (is_less_midpoint(arr, ft_get_last_node(*a)))
			{
				rra(&a);
				pb(&a, &b);
				count++;
			}
			else
				ra(&a);
		}
		num_chunks[i] = count;
		i++;
		if (ft_stack_size(a) == 1)
		{
			pb(&a, &b);
			num_chunks[i] = 1;
			num_chunks[i + 1] = '\0';
		}
	}
	common_sort_b(a, b, num_chunks);
	//free(a);
	//free(b);
}

void	common_sort_b(t_node **a, t_node **b, int *arr)
{
	int	num_chunks;
	int	chunk_len;
	
	chunk_len = 0;
	num_chunks = ft_arrlen(arr) - 1;
	while (num_chunks >= 0)
	{
		if (arr[num_chunks] == 1)
			pa(&a, &b);
		else
		{
			chunk_len = arr[num_chunks];
			sort_chunk(&a, &b, chunk_len);
		}
		num_chunks--;
	}
}

void	push_swap(t_node **a)
{
	t_node	*b;
		//cuidado, si lo hago recursivo voy a perder todos lols valores de B
	b = NULL;
	common_sort(&a, &b);
}
