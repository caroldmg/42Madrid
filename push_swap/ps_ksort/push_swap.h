/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:27:08 by cde-migu          #+#    #+#             */
/*   Updated: 2024/08/05 16:51:38 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
    int				value;
    int 			index;
	struct s_node	*prev;
    struct s_node	*next;
}	t_node;

# include <string.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"



void	show_stacks(t_node **a, t_node **b);

//funciones de stack
t_node	*ft_get_last_node(t_node *stack);
int		ft_stack_size(t_node *stack);
void	ft_new_node(t_node **stack , int nb);
int		stack_sorted(t_node *stack);
void	ft_add_index(t_node **stack);

//crear stack
void	stack_init(t_node **a, char **argv);

//gestión de errores
int 	ft_check_value(char *value);
int		ft_check_repeat(t_node *stack, int nb);
void	free_all(t_node **stack);

//ordenar
void	sort_two(t_node **a, t_node **b);
void	sort_three(t_node **a, t_node **b);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	push_swap(t_node **a, t_node **b);
void	common_sort(t_node **a, t_node **b, int size);

//swap
void	sb(t_node **b);
void	sa(t_node **a);
void	ss(t_node **a, t_node **b);

//push
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

//rotate
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

//reverse rotate
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif