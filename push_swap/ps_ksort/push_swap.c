/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:20:49 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/07 13:36:26 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **a, t_node **b)
{
	int	size;

	size = ft_stack_size(*a);
	ft_add_index(a);
	show_stacks(a, b);
	if (size < 3)
		sort_two(a, b);
	else if (size == 3)
		sort_three(a, b);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else if (size > 5)
		common_sort(a, b, size);
}

// int main() {
//   t_stack_node  *a;

//   a = malloc(sizeof(t_stack_node));
//   a->next = malloc(sizeof(t_stack_node));
//   a->next->next = malloc(sizeof(t_stack_node));
//   a->value = 42;
//   a->next->value = 1337;
//   a->next->next->value = -21;
//   a->prev = NULL;
//   a->next->prev = a;
//   a->next->next->prev = a->next;
//   a->next->next->next = NULL;

// 	printf("Valor del primer nodo: %d\n", a->value);
// 	printf("Valor del segundo nodo: %d\n", a->next->value);
//     printf("Valor del tercer nodo: %d\n", a->next->next->value); 
// 	printf("\n -------------------------- \n");

//   	sort_three(&a);

// 	printf("\n -------------------------- \n");
// 	printf("Valor del primer nodo: %d\n", a->value);
// 	printf("Valor del segundo nodo: %d\n", a->next->value);
//     printf("Valor del tercer nodo: %d\n", a->next->next->value); 
//     return 0;
// }