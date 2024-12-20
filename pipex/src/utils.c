/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:50:13 by cde-migu          #+#    #+#             */
/*   Updated: 2024/12/10 17:06:38 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	command_path(char **cmd, char **envp)
{
	char	*temp;

	temp = ft_strdup(cmd[0]);
	if (access(temp, 0) == 0)
	{
		execve(temp, cmd, envp);
		free(temp);
		perror("Error: failed execution");
		exit(EXIT_FAILURE);
	}
	else
	{
		free(temp);
		perror("Error command not found");
		exit(EXIT_FAILURE);
	}
}

char	**get_paths(char **envp)
{
	int		i;
	char	**my_paths;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	my_paths = ft_split(envp[i], ':');
	return (my_paths);
}

void	path_exec(char *argv, char **envp)
{
	int		i;
	char	**cmd;
	char	**mypaths;
	char	*temp;
	char	*executable;

	i = 0;
	cmd = ft_split(argv, ' ');
	mypaths = get_paths(envp);
	if (mypaths == NULL)
		command_path(cmd, envp);
	while (mypaths[++i])
	{
		temp = ft_strjoin(mypaths[i], "/");
		executable = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(executable, X_OK) == 0)
			execve(executable, cmd, envp);
		free(executable);
	}
	perror("Command not found");
	free_all(mypaths);
	free_all(cmd);
	exit(EXIT_FAILURE);
}

void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_error(char *str)
{
	if (str != NULL)
		perror(str);
	return (EXIT_FAILURE);
}
