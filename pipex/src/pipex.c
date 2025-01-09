/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:44:46 by cde-migu          #+#    #+#             */
/*   Updated: 2025/01/02 14:19:18 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	second_child(int file[2], char **argv)
{
	int	outfile;

	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (outfile < 0)
	{
		close(file[READ_E]);
		perror("open");
		exit(EXIT_FAILURE);
	}
	close(file[WRITE_E]);
	if (dup2(outfile, STDOUT_FILENO) < 0
		|| dup2(file[READ_E], STDIN_FILENO) < 0)
	{
		perror("dup2");
		close(outfile);
		close(file[READ_E]);
		exit(EXIT_FAILURE);
	}
	close(outfile);
	close(file[READ_E]);
	path_exec(argv[3]);
	return (EXIT_SUCCESS);
}

int	first_child(int file[2], char **argv)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		close(file[WRITE_E]);
		perror("open");
		exit(EXIT_FAILURE);
	}
	close(file[READ_E]);
	if (dup2(infile, STDIN_FILENO) < 0
		|| dup2(file[WRITE_E], STDOUT_FILENO) < 0)
	{
		perror("dup2 ");
		close(infile);
		close(file[WRITE_E]);
		exit(EXIT_FAILURE);
	}
	close(infile);
	close(file[WRITE_E]);
	path_exec(argv[2]);
	return (EXIT_SUCCESS);
}

int	pipex(char **argv, int file[2])
{
	pid_t	child1;
	pid_t	child2;
	int		status1;
	int		status2;

	child1 = fork();
	if (child1 < 0)
		return (ft_error("Fork: "));
	if (child1 == 0)
		first_child(file, argv);
	child2 = fork();
	if (child2 < 0)
		return (ft_error("Fork: "));
	if (child2 == 0)
		second_child(file, argv);
	close(file[0]);
	close(file[1]);
	waitpid(child1, &status1, 0);
	waitpid(child2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (EXIT_FAILURE);
}
