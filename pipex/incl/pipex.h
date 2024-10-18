/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:49:42 by cde-migu          #+#    #+#             */
/*   Updated: 2024/10/18 15:07:18 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"
# include "ft_printf.h"
# define WRITE_E 1
# define READ_E 0
# define SPACE ' '


void	pipex(char **argv, char **envp, int file[2]);
void	path_exec(char *argv, char **envp);
char	**get_paths(char **envp);
void	free_all(char **arr);


#endif