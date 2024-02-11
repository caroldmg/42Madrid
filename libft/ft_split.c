/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:18:33 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/11 18:25:13 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strchrlen(size_t start, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[start + i] != c && s[start + i] != '\0')
		i++;
	return (i);
}

static	size_t	count_str(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count + 1);
}

static	int	input_strings(char **arr, char const *s, size_t count, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;	

	i = 0;
	j = 0;
	while (j < count - 1)
	{
		while (s[i] == c)
			i++;
		len = strchrlen(i, s, c);
		arr[j] = (char *)malloc((len + 1) * sizeof(char));
		if (!arr[j])
			return (0);
		ft_strlcpy(arr[j], s + i, len + 1);
		i = i + len;
		j++;
	}
	arr[count - 1] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		count;

	count = count_str(s, c);
	arr = (char **)malloc(count * sizeof(char *));
	if (!arr)
		return (0);
	if (!input_strings(arr, s, count, c))
	{
		while (count--)
			free(arr[count]);
		free(arr);
		return (NULL);
	}
	return (arr);
}
/*
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
*/
