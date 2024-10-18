/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:18:33 by cde-migu          #+#    #+#             */
/*   Updated: 2024/10/18 15:54:17 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **arr, int j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
}

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
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		while (*s && *s == c)
			s++;
	}
	return (count + 1);
}

static	int	input_strings(char **arr, char const *s, size_t count, char c)
{
	size_t	i;
	int		j;
	size_t	len;	

	i = 0;
	j = 0;
	while (j < (int)count - 1)
	{
		while (s[i] == c)
			i++;
		len = strchrlen(i, s, c);
		arr[j] = (char *)malloc((len + 1) * sizeof(char));
		if (!arr[j])
		{
			free_all(arr, j);
			return (0);
		}
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

	if (!s)
		return (NULL);
	count = count_str(s, c);
	arr = (char **)malloc(count * sizeof(char *));
	if (!arr)
		return (0);
	if (!input_strings(arr, s, count, c))
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
