/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:35:28 by cde-migu          #+#    #+#             */
/*   Updated: 2024/10/04 17:21:26 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	// char	*filein;
	// char	*fileout;
	// char	*cmd1;
	// char	*cmd2;

	if (argv != 5)
	{
		printf("Para utilizar correctamente el programa: \n \t ./pipex <infile> <cmd1> <cmd2> <outfile>\n")
		return (1);
	}
	pipex(argv, argc, envp);
}

int main (int argc, char **argv)
{
	int file[2];

	if (pipe(file) < 0>)
		return ;
	

	return (0);
}