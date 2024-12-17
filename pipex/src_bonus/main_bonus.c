/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:18:35 by cde-migu          #+#    #+#             */
/*   Updated: 2024/12/16 11:46:14 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		output;
	t_files	files;

	files.infile = -1;
	files.outfile = -1;
	output = 0;
	if (argc >= 5)
		output = proccess(argv, argc, envp, &files);
	else
		ft_usage();
	return (output);
}
