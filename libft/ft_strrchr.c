/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:11:31 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/16 11:12:05 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	ch;

	ch = (char)c;
	len = ft_strlen(s);
	if (ch == '\0')
		return ((char *)(s + len));
	while (len > 0)
	{
		if (*(s + len -1) == ch)
			return ((char *)(s + len - 1));
		len--;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main() {
    const char *test_string = "Hello, world!";
    int search_char = 'o';

    // Probando la función personalizada ft_strrchr
    char *result_custom = ft_strrchr(test_string, search_char);

    // Probando la función original strrchr
    char *result_original = strrchr(test_string, search_char);

    // Comparando resultados
    if (result_custom == result_original) {
        printf("La función personalizada funciona correctamente.\n");
    } else {
        printf("La función personalizada NO produce el mismo resultado que la original.\n");
    }

    return 0;
}
*/

/*
	gcc -c ft_strlen.c -o ft_strlen.o
	gcc -c ft_strrchr.c -o ft_strrchr.o

	gcc ft_strlen.o ft_strrchr.o -o myprogram
	./myprogram
*/
