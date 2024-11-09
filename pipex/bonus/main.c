/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:42:29 by cde-migu          #+#    #+#             */
/*   Updated: 2024/11/09 16:11:27 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int	file[2];

	if (argc < 5)
	{
		printf("Para utilizar correctamente el programa: \n \t \
				./pipex <infile> <cmd1> <cmd2> <outfile> \n");
		printf("También puedes probar utilizando más de un comando \n \t \
				./pipex <infile> <cmd1> <cmd2> <cmd3> <cmd4> <outfile> ");
		printf("o puedes probar: \n \t \
				./pipex here\_doc LIMITADOR comando comando \n");
	}
	// else if (argc == 5)
	// {
	// 	if (pipe(file) < 0)
	// 		return (EXIT_FAILURE);
	// 	pipex(argv, envp, file);
	// }
	if (ft_strcmp(argv[1], "here_doc") == 0)
		here_doc(argv, envp, file);
	else
		pipex_bonus(argc - 2, argv, envp, file);
}

/* 
	- en pipex bonus, hacer un contador hasta argc para ver en qué argumento estoy
	- "here_doc" el texto de entrada es la terminal (STDIN), utiliza un limitador para decidir cuándo se cierra el archivo
	- here_doc coge las cosas con el gnl, las guardo en un arcchivo temporal (cuidado, a ver si ese archivo ya va a existir!!)
	- pipes: la del principio lee del archivo, escribe en el estandar, las del medio leen y escriben en el estandar, la ultima lee del estandar y escribe en el archivo
	- hacer la pipe dentro del padre, no fuera (en el main no)
 */