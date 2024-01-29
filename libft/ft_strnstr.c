/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:41:39 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/27 18:11:18 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	char	*aux;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			j ++;
			if (needle[j] == '\0')
			{
				aux = (char *)&haystack[i];
				return (aux);
			}
		}
		i++;
	}
	return (0);
}


/*#include <string.h>

int	main(void)
{
	const char	haystack[] = "Hello, World! This is a test string.";
	const char	needle[] = "World";
	size_t		len;
	char		*result;
	char		*originalResult;

	len = -1;
	result = ft_strnstr(haystack, needle, len);
	if (result)
		printf("La función ft_strnstr encontró la subcadena: %s\n", result);
	else
		printf("La función ft_strnstr no encontró la subcadena.\n");

	// Comparación con la función original strnstr
	
	originalResult = strnstr(haystack, needle, len);
	if ((result == NULL && originalResult == NULL) || strcmp(result,
			originalResult) == 0)
	{
		printf("La implementación de ft_strnstr es correcta.\n");
	}
	else
	{
		printf("La implementación de ft_strnstr es incorrecta.\n");
	}
	return (0);
}*/
