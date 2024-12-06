/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:18:35 by cde-migu          #+#    #+#             */
/*   Updated: 2024/12/06 15:15:17 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc >= 5)
	{
		if (ft_strcmp(argv[1], "here_doc") == 0)
		{
			i = 3;
			here_doc(argv[2], argc);
			outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		}
		else
		{
			i = 2;
			outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			infile = open(argv[1], O_RDONLY, 0777);
			dup2(infile, STDIN_FILENO);
		}
		while (i < argc - 2)
			process(argv[i++], envp);
		dup2(outfile, STDOUT_FILENO); 
		path_exec(argv[argc - 2], envp);
	}
	ft_usage();
}
