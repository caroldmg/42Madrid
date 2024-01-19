/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:26:45 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/16 11:16:28 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n && (s1[x] != '\0' || s2[x] != '\0'))
	{
		if (s1[x] != s2[x])
			return (s1[x] - s2[x]);
		x++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    // Test strings
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello, folks!";
    unsigned long n = 10;  // Number of characters to compare

    // Test your ft_strncmp
    int result = ft_strncmp(str1, str2, n);
    printf("ft_strncmp result: %d\n", result);

    // Test the standard strncmp
    int standardResult = strncmp(str1, str2, n);
    printf("strncmp result: %d\n", standardResult);

    // Compare the results
    if (result == standardResult)
    {
        printf("Test passed! ft_strncmp matches strncmp.\n");
    }
    else
    {
        printf("Test failed! ft_strncmp does not match strncmp.\n");
    }

    return 0;
}
*/