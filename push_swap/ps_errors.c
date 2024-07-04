/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:17:47 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/04 13:18:01 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	error_syntax(char *a)
// {
// 	int i;
	
// 	i = 0;
// 	if (a[i] == '+' || a[i] == '-')
// 		i++;
// 	while (a[i])
// 	{
// 		if (!ft_isdigit(a[i]))
// 		{
// 			write(1, "Error\n", 6);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// static int error_duplicate(t_stack_node *a, int nbr)
// {
// 	if (!a)
// 		return (0);
// 	while (a)
// 	{
// 		if (a->value == nbr)
// 		{
// 			write(1, "Error\n", 6);
// 			return (1);
// 		}
// 		a = a->next;
// 	}
// 	return (0);
// }