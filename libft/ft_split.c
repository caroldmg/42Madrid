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

/*
static char	*onlynull(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(char));
	if (!str)
		return (0);
	str[0] = 0;
	return (str);
}
*/

static char *create_str(char const *start, int len)
{
	char	*str;

	str = (char *)malloc((len) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, start, len);
	return (str);
}


static	int	count_strings(char const *s, char c)
{
	int		count;

	if (*s == '\0')
		count = 0;
	else
		count = 1;
	while (s != '\0')
	{
		if (*s == c)
		{
			count++;
		}
		s++;
	}
	return (count);
}
static	char	**input_strings(char **arr, char const *s, int arr_len, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j > arr_len)
	{
		if (s[i] == c)
		{
			arr[j] = create_str((s - i), i);
			if (arr[j] == 0)

			i = 0;
			j++;
		}
		i++;
		s++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	i = count_strings(s, c);
	arr = (char **)malloc(i * sizeof(char *));
	arr = input_strings(arr, s, i, c);
	return (arr);
}