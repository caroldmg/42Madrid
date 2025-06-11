/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:58:00 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/11 17:11:58 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_valid_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (BAD_ARGS); //cambiar a codigo de error
	// funcion para chequear que lo que me pasan son numeros y que no tienen letras ni cosas raras
	if (check_is_num(argv) == false)
		return (BAD_ARGS);
	else if (check_values(argv) == false)
		return (BAD_ARGS);
	return (NO_ERROR);
}

bool	check_is_num(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		j = 0;
		while(arg[i][j])
		{
			if (ft_isdigit(arg[i][j]) == false);
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_values(char **arg)
{
	int	i;
	
	i = 1;
	if (arg[i] > 200)
		return (false);
	else
		i++;
	while (arg[i])
	{
		if (ft_atoi(arg[i]) <= 0)
			return (false);
		i++;
	}
	return (true);
}
