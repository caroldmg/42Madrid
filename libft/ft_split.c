/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:18:33 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/30 17:58:39 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strchrlen(char const *str, char c)
{
	size_t	i;

	i = 0;
	while(*str != '\0' && *str != c)
		i++;
	return (i);
}

static	int	count_str(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			count++;
		}
		s++;
	}
	printf("count = %d \n", count);
	return (count);
}

static int free_all(int i, char **arr)
{
	while(i > 0)
	{
		i--;
		free(arr[i]);
	}
	printf("entro en free \n");
	free(arr);
}

static	char	**input_strings(char **arr, char const *s, int arr_len, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < arr_len)
	{
		printf("entro en input_str %d \n", i);
		while (s[i] && s[i] == c)
			i++;
		arr[j] = ft_substr(s, i, strchrlen(s + i, c));
		if (!arr[j])
		{
			free_all(j, arr);
			return (0);
		}
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;

	if (!s)
		return (0);
	count = count_str(s, c);
	arr = (char **)malloc((count + 1) * sizeof(char *));
	arr = input_strings(arr, s, count, c);
	//eliminar
	int i = 0;
	while(arr[i] != NULL)
	{
	    printf("%s\n", arr[i]);
	    i++;
	}
	return (arr);
}

#include <stdio.h>
int	main(void)
{
		const char *str1 = "Hello,World,Split,Me";
	ft_split(str1, ',');

	const char *str2 = "Lorem ipsum dolor sit amet";
	ft_split(str2, ' ');

	const char *str3 = "apple,banana,cherry,orange";
	ft_split(str3, ',');

	const char *str4 = "123-456-789-0";
	ft_split(str4, '-');

	return (0);
}