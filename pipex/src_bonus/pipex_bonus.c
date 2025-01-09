/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:05:04 by cde-migu          #+#    #+#             */
/*   Updated: 2025/01/09 17:36:07 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(char *str)
{
	if (str != NULL)
		perror(str);
	return (EXIT_FAILURE);
}

int	pipex_bonus(char *argv)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	status = 0;
	if (pipe(fd) == -1)
		return (ft_error("pipe: "));
	pid = fork();
	if (pid == -1)
		return (ft_error("Fork: "));
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		path_exec(argv);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, &status, 0);
	}
	if (status && WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}

int	last_child(t_files *files, char **argv, int argc)
{
	int	pid;
	int	status;

	status = 0;
	pid = fork();
	if (pid == -1)
		return (ft_error("Fork: "));
	if (pid == 0)
	{
		dup2(files->outfile, STDOUT_FILENO);
		path_exec(argv[argc - 2]);
	}
	else
		waitpid(pid, &status, 0);
	if (status && WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}