/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:35:28 by cde-migu          #+#    #+#             */
/*   Updated: 2024/10/15 11:35:49 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	// char	*filein;
	// char	*fileout;
	// char	*cmd1;
	// char	*cmd2;
	int file[2];

	if (argv != 5)
	{
		printf("Para utilizar correctamente el programa: \n \t ./pipex <infile> <cmd1> <cmd2> <outfile>\n");
		return (1);
	}
	if (pipe(file) < 0)
		return (1)
	// primero, parseo y comprobar que los argumentos existen y son válidos
	parse(argv);
	pipex(argc, argv, envp, file);
}

path_exec(char *argv, char **envp)
{
	char	**cmd,
	char	**mypaths;

	cmd = ft_split(argv, ' ');
	mypaths = paths();
	while (mypaths[++i])
	{
		cmd = ft_strjoin(mypaths[i], cmd);
		execve(mypaths[i], cmd, NULL);
		perror("Error");
		free(cmd);
	}
	return (EXIT_FAILURE);
}

char	**paths(char *envp)
{
	char *PATH_from_envp;
	char **mypaths;
	char **mycmdargs;
// retrieve the line PATH from envp
	PATH_from_envp = ft_substr(envp ....);
	mypaths = ft_split(PATH_from_envp, ":"); 
	mycmdargs = ft_split(ag[2], " ");
}
