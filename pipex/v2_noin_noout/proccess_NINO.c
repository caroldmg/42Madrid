/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:45:46 by cde-migu          #+#    #+#             */
/*   Updated: 2025/01/13 12:54:21 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	proccess_NINO(char **argv, int argc)
{
	int	i;
	int	output;
	int	last_output;

	i = 1;
	output = 0;

	while (i < argc - 1)
	{
		output = pipex_bonus(argv[i]);
		i++;
	}
	last_output = last_child_NINO(argv, argc);
	if (last_output && output != last_output)
		output = last_output;
	return (output);
}
