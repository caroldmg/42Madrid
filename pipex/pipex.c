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
	char *PATH_from_envp;
	char **mypaths;
	char **mycmdargs;
// retrieve the line PATH from envp
	PATH_from_envp = ft_substr(envp ....);
	mypaths = ft_split(PATH_from_envp, ":"); 
	mycmdargs = ft_split(ag[2], " ");
}

void second_child(int file[2], char **argv, char **envp)
{
	int outfile;

	outfile = open(argv[4], );
	if (outfile < 0)
		perror("open: ")
	close(file[WRITE_E]);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		return ;
	if (dup2(file[READ_E], STDIN_FILENO) < 0)
		return ;
	close(file[READ_E]);
}

// void	first_child(int file[2], char **argv, char **envp)
// {
// 	int 	i;
// 	char	**mypaths;
// 	char	**splitted;

// 	i = -1;
// 	splitted = ft_split(argv[2], ' ');
// 	if (dup2(fd, STDIN_FILENO) < 0)
// 		return ;
// 	close(file[READ_E]);
// 	if (dup2(file[WRITE_E], STDOUT_FILENO) < 0)
// 		return ;
// 	close(file[READ_E]);
// 	close(file[WRITE_E]);
// 	mypaths = paths();
// 	while (mypaths[++i])
// 	{
// 		cmd = ft_strjoin(mypaths[i], cmd);
// 		execve(mypaths[i], cmd, NULL);
// 		perror("Error");
// 		free(cmd);
// 	}
// 	return (EXIT_FAILURE);
// }

void	first_child(int file[2], char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		// error de que no se ha abierto correctamente
	{
		perror("open: ");
	}
	close(file[READ_E]);
	if (dup2(infile, STDIN_FILENO));
	if (dup2(file[WRITE_E], STDOUT_FILENO) < 0)
		return ;
	path_exec(argv[2], envp);
}

// void	pipex(int fd1, int fd2, char *cmd1, char *cmd2)
// {
// 	int		file[2];
// 	int		status;
// 	pid_t	child1;
// 	pid_t	child2;

// 	if (pipe(file) < 0)
// 		return (1);
// 	child1 = fork();
// 	if (child1 < 0)
// 		return (perror("Fork: "));
// 	// a los errores les podria asignar un numero para saber en qué momento ha fallado 
// 	if (child1 == 0)
// 		first_child(fd1, cmd1, file);
// 	child2 = fork();
// 	if (child2 < 0)
// 		return (perror("Fork: "));
// 	if (child2 == 0)
// 		second_child(fd2, cmd2);
// 	close(file[0]);
// 	close(file[1]);
// 	waitpid(child1, &status, 0);
// 	waitpid(child2, &status, 0);
// }

void	pipex(int argc, char **argv, char **envp, int file[2])
{
	pid_t	child1;
	pid_t	child2;

	if (pipe(file) < 0)
		return (1);
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork: "));
	// a los errores les podria asignar un numero para saber en qué momento ha fallado 
	if (child1 == 0)
		first_child(file, argv, envp);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		second_child(fd2, cmd2);
	close(file[0]);
	close(file[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

parse(char **argv)
{

}