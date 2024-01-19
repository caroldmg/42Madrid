/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:23:35 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/18 12:45:30 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_spaces(char c)
{
	return ((c == ' ' || c == '\n' || c == '\t' || c == '\v'
			|| c == '\f' || c == '\r') || (c == '+'));
}

static	int	ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	i = 0;
	while (str[i] != '\0' && ft_is_spaces(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *=  -1;
		i++;
	}
	while (ft_is_number(str[i]))
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return ((int)nbr * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    // Test cases
    const char *test_strings[] = {"123", "-456", "789", "0", "abc", "+987"};

    // Test your function against the original atoi
    for (unsigned long i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); i++)
    {
        int result_original = atoi(test_strings[i]);
        int result_custom = atoi(test_strings[i]);

        printf("Original atoi result for \"%s\": %d\n", test_strings[i], result_original);
        printf("Custom atoi result for \"%s\": %d\n", test_strings[i], result_custom);

        // Compare results
        if (result_original == result_custom)
            printf("Results match!\n");
        else
            printf("Results do not match!\n");

        printf("\n");
    }

    return 0;
}
*/