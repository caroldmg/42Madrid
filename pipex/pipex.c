/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:44:46 by cde-migu          #+#    #+#             */
/*   Updated: 2024/10/08 12:22:28 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
- recoger todos los paths posibles, separarlos con split usando : como separador, 
- en cada llamada (con cada comando) recorrer todos estos posibles paths hasta encontrar el adecuad y que funcione
- ese path mandarlo a execve
 */
char	**paths(char *envp)
{
	char	**mypaths;
	char	*env_paths;

	// env_paths = ft_substr(envp, 0, )
	mypaths = ft_split(env_paths, ' ');
}

void	first_child(int fd, char *cmd, int file[2])
{
	int 	i;
	char	**mypaths;

	i = -1;
	if (dup2(fd, STDIN_FILENO) < 0)
		return ;
	close(file[READ_E]);
	if (dup2(file[WRITE_E], STDOUT_FILENO) < 0)
		return ;
	close(file[READ_E]);
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

void	pipex(int fd1, int fd2, char *cmd1, char *cmd2)
{
	int		file[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	// pipe(file);
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork: "));
	if (child1 == 0)
		first_child(fd1, cmd1, file);
	child1 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		second_child(fd2, cmd2);
	close(file[0]);
	close(file[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}
