/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:35:28 by cde-migu          #+#    #+#             */
/*   Updated: 2024/11/25 12:04:26 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	file[2];
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("%d --> %s \n", i, envp[i]);
		i++;
	}

	if (argc != 5)
	{
		printf("Para utilizar correctamente el programa: \n \t \
				./pipex <infile> <cmd1> <cmd2> <outfile> \n");
		return (EXIT_FAILURE);
	}
	if (pipe(file) < 0)
		return (EXIT_FAILURE);
	pipex(argv, envp, file);
}
