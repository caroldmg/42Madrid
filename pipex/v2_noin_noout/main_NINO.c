/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:18:35 by cde-migu          #+#    #+#             */
/*   Updated: 2025/01/13 12:54:29 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		output;
	// t_files	files;

	// files.infile = -1;
	// files.outfile = -1;
	// output = 0;
	// if (argc >= 5)
		output = proccess_NINO(argv, argc);
	// else
	// 	ft_usage();
	return (output);
}
