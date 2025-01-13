/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:50:13 by cde-migu          #+#    #+#             */
/*   Updated: 2025/01/13 12:42:07 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths()
{
	char	*env_paths;
	char	**my_paths;

	my_paths = NULL;
	env_paths = getenv("PATH");
	if (env_paths != NULL)
		my_paths = ft_split(env_paths, ':');
	return (my_paths);
}

void	path_exec(char *argv)
{
	int		i;
	char	**cmd;
	char	**mypaths;
	char	*temp;
	char	*executable;

	i = 0;
	cmd = ft_split(argv, ' ');
	mypaths = get_paths();
	while (mypaths[++i])
	{
		temp = ft_strjoin(mypaths[i], "/");
		executable = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(executable, X_OK) == 0)
			execve(executable, cmd, mypaths);
		free(executable);
	}
	perror("hola not found");
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

void	ft_usage(void)
{
	ft_printf("\033[31mError: Bad argument\n\e[0m");
	ft_printf("Ex: ./pipex_bonus <file1> <cmd1> <cmd2> <...> <file2>\n");
	ft_printf("\t./pipex_bonus \"here_doc\" <LIMITER> <cmd> \
					<cmd1> <...> <file>\n");
	exit(EXIT_SUCCESS);
}
