#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	if (argc >= 2)
	{
		a = NULL;
		b = NULL;
		int i = 1;
		
		while (i < argc)
		{
			ft_new_node(&a, *argv[i]);
			i++;
		}
		printf ("the node vlue is %d \n"
				"\t the prev is %d \n"
				"\t the next is %d \n \n", a->value, a->prev ? a->prev->value : 0, a->next ? a->next->value : 0);
		
				// PUSH
		pb(&a, &b);
		pb(&a, &b);
		pb(&a, &b);
		pb(&a, &b);
		pb(&a, &b);
		ft_printablist(a, b);

		pa(&a, &b);
		ft_printablist(a, b);
	
				// SWAP
		sa(&a);
		ft_printablist(a, b);

		sb(&b);
		ft_printablist(a, b);
		
		ss(&a, &b);
		ft_printablist(a, b);

				// ROTATE
		ra(&a);
		ft_printablist(a, b);

		rb(&b);
		ft_printablist(a, b);
		
		rr(&a, &b);
		ft_printablist(a, b);

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