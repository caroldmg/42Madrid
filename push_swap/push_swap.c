/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:20:49 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/04 13:46:28 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int main ()
{
	t_stack_node	*a;
	a = NULL;
	
	ft_new_node(&a, -4);
	ft_new_node(&a, 10);
	ft_new_node(&a, 5);
	
	t_stack_node	*ca = a;
	for (int i = 0; i < 10, ++i)
	{
		ca = a;
		while (ca)
		{
			printf ("the node vlue is %d \n"
				"\t the prev is %d \n"
				"\t the next is %d \n \n", a->value, a->prev ? a->prev->value : 0, a->next ? a->next->value : 0);
				ca = ca->next;
		}
	}
}

int ft_printlist(t_stack_node *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		printf ("nb= %i\n", lst->value);
		lst = lst->next;
	}
	printf ("\n");
	return(count);
}

int ft_printablist(t_stack_node *a, t_stack_node *b)
{
	int	count;

	count = 0;
	while (a != NULL || b != NULL)
	{
		count++;
		printf ("%i  %i\n", a->value, b->value);
		a = a->next;
		b = b->next;
	}
	while (a != NULL)
	{
		count++;
		printf ("%i   \n", a->value);
		a = a->next;
	}
	while (b != NULL)
	{
		count++;
		printf ("   %i\n", b->value);
		b = b->next;
	}
	printf ("_  _\n");
	printf ("a  b\n");
	printf ("\n");
	return(count);
}

// int ft_printalist(t_stack_node *a)
// {
// 	int	count;

// 	count = 0;
// 	while (a != NULL)
// 	{
// 		count++;
// 		printf ("%i\n", a->value);
// 		printf ("the node vlue is %d \n"
// 				"\t the prev is %d \n"
// 				"\t the next is %d \n \n", a->value, a->prev ? a->prev->value : 0, a->next ? a->next->value : 0);
// 		a = a->next;
// 	}
// 	while (a != NULL)
// 	{
// 		count++;
// 		printf ("%i   \n", a->value);
// 		a = a->next;
// 	}
// 	printf ("_  _\n");
// 	printf ("a  b\n");
// 	printf ("\n");
// 	return(count);
// }

// t_stack_node	*stack(char *argv[])
// {
// 	int		x;
// 	t_stack_node	*a;
// 	t_stack_node	*new;
// 	t_stack_node	*current;

// 	x = 2;
// 	a = ft_new_node(ft_atoi(argv[1])); // pasar a long para comprobar que no me pasan un maximo
// 	current = a;
// 	while (argv[x] != NULL)
// 	{
// 		new = ft_new_node(ft_atoi(argv[x]));
// 		current->next = new;
// 		current = new;
// 		x++;
// 	}
// 	return(a);
// }

// t_stack_node *stack_falso(void)
// {
//     t_stack_node *a = ft_new_node(6);
//     t_stack_node *current = a;
    
//     for (int i = 7; i <= 10; i++)
//     {
//         t_stack_node *new_node = ft_new_node(i);
//         current->next = new_node;
// 		current->next->prev = current;
//         current = new_node;
//     }

//     return a;
// }

// int	main(int argc, char *argv[])
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;

// 	if (argc >= 2)
// 	{
// 		a = NULL;
// 		b = NULL;
// 		int i = 1;
		
// 		while (i < argc)
// 		{
// 			ft_new_node(&a, *argv[i]);
// 			i++;
// 		}
// 		printf ("the node vlue is %d \n"
// 				"\t the prev is %d \n"
// 				"\t the next is %d \n \n", a->value, a->prev ? a->prev->value : 0, a->next ? a->next->value : 0);
		
// 				// PUSH
// 		pb(&a, &b);
// 		pb(&a, &b);
// 		pb(&a, &b);
// 		pb(&a, &b);
// 		pb(&a, &b);
// 		ft_printablist(a, b);

// 		pa(&a, &b);
// 		ft_printablist(a, b);
	
// 				// SWAP
// 		sa(&a);
// 		ft_printablist(a, b);

// 		sb(&b);
// 		ft_printablist(a, b);
		
// 		ss(&a, &b);
// 		ft_printablist(a, b);

// 				// ROTATE
// 		ra(&a);
// 		ft_printablist(a, b);

// 		rb(&b);
// 		ft_printablist(a, b);
		
// 		rr(&a, &b);
// 		ft_printablist(a, b);

// 				// REVERS ROTATE
// 		rra(&a);
// 		ft_printablist(a, b);

// 		rrb(&b);
// 		ft_printablist(a, b);
		
// 		rrr(&a, &b);
// 		ft_printablist(a, b);

// 		return (0);
// 	}
// }