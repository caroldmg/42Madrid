/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:21:27 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/26 12:05:55 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef	struct s_node
{
	int	value;
	struct s_node	*prev;
    struct s_node	*next;
}	t_node;

// typedef struct	s_stack {
// 	struct s_node	*top;
// }				t_stack;

# include <string.h>
# include <limits.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

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

//funciones de stack
t_node	*ft_get_last_node(t_node *stack);
int		ft_stack_size(t_node *stack);
void	ft_new_node(t_node **stack, int nb);

//parseo y errores
void	stack_init(t_node **a, char **argv);
int 	ft_check_value(char *value);
int		ft_check_repeat(t_node *stack, int nb);
void	free_all(t_node **stack);

//funciones array
int 	*quicksort(int* arr, int low, int high);
int		*stack_to_array(t_node *stack);
int		ft_arrlen(int *arr);
int		*ft_get_num_chunks(int len);
int		ft_len_to_midpoint(int *arr);
int		is_less_midpoint(int *arr, int nb);

//ordenar stack
int		is_sorted(t_node *stack);
void	sort_three(t_node **a);
void	common_sort_a(t_node **a, t_node **b);
void	common_sort_b(t_node **a, t_node **b, int *num_chunks);

#endif