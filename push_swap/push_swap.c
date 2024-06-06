/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:20:49 by cde-migu          #+#    #+#             */
/*   Updated: 2024/05/28 13:42:57 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* 
    int main(int argc, char **argv)
    {
        t_stack_node    *a;
        t_stack_node    *b;

        a = NULL;
        b = NULL;

        if (srgc == 1 || (argc == 2 && !argv[1][0]))
            return (1); //erro
        else if (argc == 2)
            argv = ft_split(argv[1], ' ');

        stack_init(&a, argv + 1, argc == 2);
        if (!stack_sorted(a))
        {
            if (stack_len(a) == 2)
                sa(&a, false);
            else if (stack_len(a) == 3)
                tiny_sort(&a);
            else
                push_swap(&a, &b);
        }
        free_stack(&a);
    }
*/

//for the split function I will use my libft's one. 

#include <stdio.h>
#include "push_swap.h"

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

t_stack_node	*stack(char *argv[])
{
	int		x;
	t_stack_node	*a;
	t_stack_node	*new;
	t_stack_node	*current;

	x = 2;
	a = ft_new_node(ft_atoi(argv[1])); // pasar a long para comprobar que no me pasan un maximo
	current = a;
	while (argv[x] != NULL)
	{
		new = ft_new_node(ft_atoi(argv[x]));
		current->next = new;
		current = new;
		x++;
	}
	return(a);
}

t_stack_node *stack_falso(void)
{
    t_stack_node *a = ft_new_node(6);
    t_stack_node *current = a;
    
    for (int i = 7; i <= 10; i++)
    {
        t_stack_node *new_node = ft_new_node(i);
        current->next = new_node;
		current->next->prev = current;
        current = new_node;
    }

    return a;
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node *b;

	if (argc)
	{
		a = stack(argv);
		b = stack_falso();
		ft_printablist(a, b);

				// SWAP
		// sa(&a);
		// ft_printablist(a, b);

		// sb(&b);
		// ft_printablist(a, b);
		
		// ss(&a, &b);
		// ft_printablist(a, b);

				// PUSH
		// pa(&a, &b);
		// ft_printablist(a, b);

		// pb(&a, &b);
		// ft_printablist(a, b);

				// ROTATE
		// ra(&a);
		// ft_printablist(a, b);

		// rb(&b);
		// ft_printablist(a, b);
		
		// rr(&a, &b);
		// ft_printablist(a, b);

				// REVERS ROTATE
		rra(&a);
		ft_printablist(a, b);

		rrb(&b);
		ft_printablist(a, b);
		
		rrr(&a, &b);
		ft_printablist(a, b);

		return (0);
	}
}