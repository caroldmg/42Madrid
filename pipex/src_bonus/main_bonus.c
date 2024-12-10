/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:18:35 by cde-migu          #+#    #+#             */
/*   Updated: 2024/12/10 18:28:21 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;
	int err;
	int x;

	err = 0;
	x = 0;
	if (argc >= 5)
	{
		if (ft_strcmp(argv[1], "here_doc") == 0)
		{
			i = 3;
			outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND);
			if (outfile < 0)
			{
				perror("open");
				exit(EXIT_FAILURE);
			}
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
			if (outfile < 0)
			{
				perror("open");
				exit(EXIT_FAILURE);
			}
			infile = open(argv[1], O_RDONLY);
			if (infile < 0)
			{
				perror("open");
				exit(EXIT_FAILURE);
			}
			dup2(infile, STDIN_FILENO);
		}
		while (i < argc - 2)
		{
			x = pipex_bonus(argv[i++], envp);
			if (err == 0)
				err = x;
		}
		dup2(outfile, STDOUT_FILENO);
		path_exec(argv[argc - 2], envp);
	}
	else
		ft_usage();
	return (err);
}
