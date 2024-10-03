/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:44:46 by cde-migu          #+#    #+#             */
/*   Updated: 2024/10/03 15:50:38 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int fd1, int fd2, char *cmd1, char *cmd2)
{
	int		file[2];
	int		status;
	pid_t	child1;
	pid_t	child2;
	
	pipe(file);
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork: "));
	if (child1 == 0)
		first_child(fd1, cmd1);
	child1 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		second_child(fd2, cmd2);
	close(file[0]);
	close(file[1]);

}
