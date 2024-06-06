/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:27:08 by cde-migu          #+#    #+#             */
/*   Updated: 2024/05/28 13:43:43 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack_node
{
	struct s_stack_node *prev;
    int value;
    //int *index;
    struct s_stack_node   *next;
}	t_stack_node;

# include <string.h>
# include <limits.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

//funciones de stack
t_stack_node	*ft_get_last_node(t_stack_node *stack);
int				ft_stack_size(t_stack_node *stack);
t_stack_node	*ft_new_node(int nb);

//crear stack
//void			stack_init(t_stack_node **a, char **argv);

//swap
void			sb(t_stack_node **b);
void			sa(t_stack_node **a);
void			ss(t_stack_node **a, t_stack_node **b);

//push
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);

//rotate
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

//reverse rotate
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);

#endif