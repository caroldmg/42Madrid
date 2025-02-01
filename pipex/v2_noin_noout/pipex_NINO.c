/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_NINO.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:05:04 by cde-migu          #+#    #+#             */
/*   Updated: 2025/02/01 13:12:49 by cde-migu         ###   ########.fr       */
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
		close(fd[READ_E]);
		dup2(fd[WRITE_E], STDOUT_FILENO);
		path_exec(argv);
	}
	else
	{
		close(fd[WRITE_E]);
		dup2(fd[READ_E], STDIN_FILENO);
		waitpid(pid, &status, 0);
	}
	if (status && WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}

int	last_child_NINO(char **argv, int argc)
{
	int	pid;
	int	status;

	status = 0;
	pid = fork();
	if (pid == -1)
		return (ft_error("Fork: "));
	if (pid == 0)
		path_exec(argv[argc - 1]);
	else
		waitpid(pid, &status, 0);
	if (status && WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}