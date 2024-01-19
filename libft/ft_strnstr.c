/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:41:39 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/16 11:16:45 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	char	*aux;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
			j++;
		else
			j = 0;
		if (needle[j] == '\0')
		{
			aux = (char *)&haystack[i - j + 1];
			return (aux);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main() {
    const char haystack[] = "Hello, World! This is a test string.";
    const char needle[] = "World";
    unsigned long len = strlen(haystack);

    char *result = ft_strnstr(haystack, needle, len);

    if (result) {
        printf("La función ft_strnstr encontró la subcadena: %s\n", result);
    } else {
        printf("La función ft_strnstr no encontró la subcadena.\n");
    }

    // Comparación con la función original strnstr
    char *originalResult = strnstr(haystack, needle, len);

    if ((result == NULL && originalResult == NULL) || strcmp(result, originalResult) == 0) {
        printf("La implementación de ft_strnstr es correcta.\n");
    } else {
        printf("La implementación de ft_strnstr es incorrecta.\n");
    }

    return 0;
}
*/
