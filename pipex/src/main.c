/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:35:28 by cde-migu          #+#    #+#             */
/*   Updated: 2024/10/25 16:28:49 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	file[2];

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

/* 
	creo que Jorge lo que hacía era coger los paths y separarlos desde el principio;
	de ese modo hago la funcion de get_paths solo una vez, y no una por comando
 */