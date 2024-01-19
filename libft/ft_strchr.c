/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:22:02 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/14 18:38:11 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != '\0')
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	else
		return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    // Cadena para probar
    const char *originalStr = "Hello, World!";
    const char *customStr = "Hello, World!";

    // Carácter a buscar
    int targetChar = 'o';

    // Utiliza strchr para encontrar el carácter en la cadena original
    char *originalResult = strchr(originalStr, targetChar);

    // Utiliza ft_strchr para encontrar el carácter en la cadena custom
    char *customResult = ft_strchr(customStr, targetChar);

    // Compara los resultados
    if ((originalResult == NULL && customResult == NULL) || (originalResult && customResult && *originalResult == *customResult)) {
        printf("¡La función ft_strchr funciona correctamente!\n");
    } else {
        printf("Hay un problema con la función ft_strchr.\n");
    }

    return 0;
}
*/