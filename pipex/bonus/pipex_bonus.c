/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:57:50 by cde-migu          #+#    #+#             */
/*   Updated: 2024/10/25 16:27:50 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_children(int argc, char **argv, char **envp, int file[2], int i)
{
	if (i == 1)
		first_child(file, argv, envp);
	else if (i == argc)
		last_child(file, argv, envp);
	else
		middle_child(file, argv, envp, i);
}
/* 
	last child es como second child en el anterior,
	middle child necesita la i para saber qué comando debe coger
 */

void	pipex(int argc, char **argv, char **envp)
{
	int 	i;
	int		file[2];
	pid_t	child;

	i = 1;
	while (i <= argc)
	{
		child = fork();
		if (child < 0)
			return (perror("Fork: "));
		if (child == 0)
			make_children(argc, argv, envp, file, i);
	}
}
