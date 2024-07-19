/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:20:49 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/15 17:24:35 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

// int main ()
// {
		//PROBAR LAS OPERACIONES
// 	t_stack_node	*a;
	
// 	a = NULL;
// 	ft_new_node(&a, -4);
// 	ft_new_node(&a, 8);
// 	ft_new_node(&a, 9);
	
// 	t_stack_node	*ca = a;
// 	for (int i = 0; i < 10; ++i)
// 	{
// 		ca = a;
// 		while (ca)
// 		{
// 			printf ("the node vlue is %d \n"
// 				"\t the prev is %d \n"
// 				"\t the next is %d \n \n", ca->value, ca->prev ? ca->prev->value : 0, ca->next ? ca->next->value : 0);
// 				ca = ca->next;
// 		}
// 		ra(&a);
// 		printf("*************************** \n \n");
// 	}
// }

int main() {
  t_stack_node  *a;
  
  a = malloc(sizeof(t_stack_node));
  a->next = malloc(sizeof(t_stack_node));
  a->next->next = malloc(sizeof(t_stack_node));
  a->value = 42;
  a->next->value = 1337;
  a->next->next->value = -21;
  a->prev = NULL;
  a->next->prev = a;
  a->next->next->prev = a->next;
  a->next->next->next = NULL;
  
	printf("Valor del primer nodo: %d\n", a->value);
	printf("Valor del segundo nodo: %d\n", a->next->value);
    printf("Valor del tercer nodo: %d\n", a->next->next->value); 
	printf("\n -------------------------- \n");

  	sort_three(&a);
	
	printf("\n -------------------------- \n");
	printf("Valor del primer nodo: %d\n", a->value);
	printf("Valor del segundo nodo: %d\n", a->next->value);
    printf("Valor del tercer nodo: %d\n", a->next->next->value); 
    return 0;
}