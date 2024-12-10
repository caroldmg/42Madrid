/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:49:42 by cde-migu          #+#    #+#             */
/*   Updated: 2024/12/10 17:12:18 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

# define ERROR_E 2
# define WRITE_E 1
# define READ_E	 0
# define SPACE ' '
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define R_BYTES 1

/* enum	e_errors
{
	wrong_input = 1,
	pipe_error = 2,
	fork_error = 3,
	path_error = 4,
}	t_error; */

int		pipex(char **argv, char **envp, int file[2]);

// BONUS
void	ft_usage(void);
void	here_doc(char *limit, int argc);
// int		pipex_bonus(int argc, char **argv, char **envp);
int		pipex_bonus(char *argv, char **envp);

// UTILS

void	path_exec(char *argv, char **envp);
char	**get_paths(char **envp);
void	free_all(char **arr);
int		ft_error(char *str);

#endif