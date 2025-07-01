/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:54:08 by cde-migu          #+#    #+#             */
/*   Updated: 2025/07/01 12:35:42 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_all	*all;
	int		ret_code;

	all = (t_all *)ft_calloc(1, sizeof(t_all));
	if (!all)
		return (error_msg(ERROR_MALLOC));
	if (check_valid_args(argc, argv) != NO_ERROR)
		return (error_msg(BAD_ARGS));
	all->philosophers = create_program(argv);
	if (!all->philosophers)
		return (error_msg(INIT_ERROR));
	all->monitor = init_monitor(all->philosophers);
	if (!all->monitor)
	{
		free(all->philosophers);
		return (error_msg(INIT_ERROR));
	}
	link_philo_monitor(all);
	ret_code = start_philo_life(all->philosophers);
	return (check_return_life(ret_code, all));
}
