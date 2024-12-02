/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:44:46 by cde-migu          #+#    #+#             */
/*   Updated: 2024/12/02 19:43:13 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_child(int file[2], char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile < 0)
	{
		close(file[READ_E]);
		perror("open: ");
	}
	close(file[WRITE_E]);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		return ;
	close(outfile);
	if (dup2(file[READ_E], STDIN_FILENO) < 0)
		return ;
	close(file[READ_E]);
	path_exec(argv[3], envp);
}

void	first_child(int file[2], char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0666);
	if (infile < 0)
	{
		close(file[WRITE_E]);
		perror("open: ");
	}
	close(file[READ_E]);
	if (dup2(infile, STDIN_FILENO) < 0)
		return ;
	close(infile);
	if (dup2(file[WRITE_E], STDOUT_FILENO) < 0)
		return ;
	close(file[WRITE_E]);
	path_exec(argv[2], envp);
}

void	pipex(char **argv, char **envp, int file[2])
{
	pid_t	child1;
	pid_t	child2;
	int		status;

	child1 = fork();
	if (child1 < 0)
		return (perror("Fork: "));
	if (child1 == 0)
		first_child(file, argv, envp);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		second_child(file, argv, envp);
	close(file[0]);
	close(file[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}
