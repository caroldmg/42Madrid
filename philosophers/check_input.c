/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:58:00 by cde-migu          #+#    #+#             */
/*   Updated: 2025/06/25 12:39:49 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_valid_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (BAD_ARGS);
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
		while (arg[i][j])
		{
			if (ft_isdigit(arg[i][j]) == false)
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
	if (ft_atoi(arg[i]) > 200 && ft_atoi(arg[i]) <= 0)
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

void	init_prgm_data(char **argv, t_philo *program)
{
	program->num_philo = ft_atoi(argv[1]);
	program->time_to_die = ft_atoi(argv[2]);
	program->time_to_eat = ft_atoi(argv[3]);
	program->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		program->nb_meals_to_eat = ft_atoi(argv[5]);
	else
		program->nb_meals_to_eat = -1;
}
