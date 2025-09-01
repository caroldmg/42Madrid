/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:56:07 by cde-migu          #+#    #+#             */
/*   Updated: 2025/09/01 16:43:56 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <ctype.h>

void	printUpper(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (i < argc)
	{
		j = 0;
		len = strlen(argv[i]);
		while (argv[i][j])
		{
			std::cout << (char) toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printUpper(argc, argv);
		return (0);
	}
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
