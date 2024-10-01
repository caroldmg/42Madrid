#include "push_swap.h"

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
