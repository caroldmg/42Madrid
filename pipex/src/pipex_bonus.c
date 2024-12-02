/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:05:04 by cde-migu          #+#    #+#             */
/*   Updated: 2024/12/02 19:02:05 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, ERROR_E);
	exit(EXIT_FAILURE);
}

void	ft_usage(void)
{
	ft_putendl_fd("argumentos no válidos. \n \t Utilización: \t ./pipex \
			archivo1 comando1 comando2 comando3 ... comandon archivo2", ERROR_E);
}

/* int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		error();
	return (file);
} */

void	process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		perror("pipe: ");
	pid = fork();
	if (pid == -1)
		perror("fork: ");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		path_exec(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limit, int argc)
{
	pid_t	read;
	int		file[2];
	char	*line;

	if (argc < 6)
		return (ft_error("Utilización: \t ./pipex here_doc LIMITADOR \
				comando comando1 archivo"));
	if (pipe(file) < 0)
		perror("pipe: ");
	read = fork();
	if (read == 0)
	{
		close(file[READ_E]);
		while (get_next_line(READ_E))
		{
			if (ft_strcmp(line, limit) == 0)
				exit(EXIT_SUCCESS);
			write(file[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(file[1]);
		dup2(file[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (argc >= 5)
	{
		if (ft_strcmp(argv[1], "here_doc") == 0)
		{
			i = 3;
			fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
			filein = open(argv[1], O_RDONLY, 0777);
			dup2(filein, STDIN_FILENO);
		}
		while (i < argc - 2)
			process(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		path_exec(argv[argc - 2], envp);
	}
	ft_usage();
}
