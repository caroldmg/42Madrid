/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:45:46 by cde-migu          #+#    #+#             */
/*   Updated: 2025/01/09 17:20:53 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_default(char **argv, int argc, t_files *files)
{
	files->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (files->outfile < 0)
	{
		perror("open outfile");
		exit(EXIT_FAILURE);
	}
	files->infile = open(argv[1], O_RDONLY);
	if (files->infile < 0)
	{
		perror("open infile");
		exit(EXIT_FAILURE);
	}
	dup2(files->infile, STDIN_FILENO);
	return (EXIT_DEFAULT_O);
}

int	open_here_doc(char **argv, int argc, t_files *files)
{
	files->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (files->outfile < 0)
	{
		perror("open outfile");
		exit(EXIT_FAILURE);
	}
	here_doc(argv[2], argc);
	return (EXIT_HEREDOC_O);
}

int	proccess(char **argv, int argc, t_files *files)
{
	int	i;
	int	output;

	i = 0;
	output = 0;
	if (ft_strcmp(argv[1], "here_doc") == 0)
		i = open_here_doc(argv, argc, files);
	else
		i = open_default(argv, argc, files);
	while (i < argc - 2)
	{
		output = pipex_bonus(argv[i]);
		i++;
	}
	dup2(files->outfile, STDOUT_FILENO);
	path_exec(argv[argc - 2]);
	return (output);
}
