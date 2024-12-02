/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:57:50 by cde-migu          #+#    #+#             */
/*   Updated: 2024/12/02 19:42:09 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_children(int argc, char **argv, char **envp, int file[2], int i)
{
	if (i == 1)
		first_child(file, argv, envp);
	else if (i == argc)
		last_child(file, argc, argv, envp);
	else
		middle_child(file, argv, envp, i);
}
/* 
	last child es como second child en el anterior,
	middle child necesita la i para saber qué comando debe coger
 */

void	first_child(int file[2], char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0666);
	if (infile < 0)
	{
		close(file[WRITE_E]);
		perror("open: ");
		exit(1);
	}
	close(file[READ_E]);
	if (dup2(infile, STDIN_FILENO) < 0)
	{
        close(infile);
        perror("dup2: ");
        exit(1);
    }
	close(infile);
	if (dup2(file[WRITE_E], STDOUT_FILENO) < 0)
	{
        perror("dup2: ");
        exit(1);
    }
	close(file[WRITE_E]);
	path_exec(argv[2], envp);
}

void	middle_child(int file[2], char **argv, char **envp, int i)
{
	close(file[READ_E]);
	if (dup2(file[WRITE_E], STDOUT_FILENO) < 0)
	{
        perror("dup2: ");
        exit(1);
    }
	path_exec(argv[i], envp);
}

void	last_child(int file[2], int argc, char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile < 0)
	{
		close(file[READ_E]);
		perror("open: ");
	}
	close(file[WRITE_E]);
	if (dup2(outfile, STDOUT_FILENO) < 0)
	{
        perror("dup2: ");
        exit(1);
    }
	close(outfile);
	if (dup2(file[READ_E], STDIN_FILENO) < 0)
	{
        perror("dup2: ");
        exit(1);
    }
	close(file[READ_E]);
	path_exec(argv[argc - 1], envp);
}

/* void	pipex(int argc, char **argv, char **envp)
{
	int 	i;
	int		status;
	int		file[2];
	pid_t	child;

	i = 1;
	while (i <= argc)
	{
		if (pipe(file) < 0)
			return (perror("Pipe: "));
		child = fork();
		if (child < 0)
			return (perror("Fork: "));
		if (child == 0)
			handle_children(argc, argv, envp, file, i);
		waitpid(child, &status, 0);
		close(file[READ_E]);
		close(file[WRITE_E]);
		i++;
	}
} */
