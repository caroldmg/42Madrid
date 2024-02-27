/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:31:32 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/16 12:50:54 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static char	*trim_helper(char *s1, char *set, char *ptr)
{
	int		i;
	int		j;
	int		is_same;

	i = 0;
	j = 0;
	is_same = 0;
	while (set[j] != '\0')
	{
		while(s1[i] != '\0' && is_same == 0)
		{
			is_same = 1;
			if (s1[i] == set[j])
			{
				ptr = ft_strchr(s1, s1[i + 1]);
				is_same = 0;
			}
			i++;
		}
		j++;
	}
	return (ptr);
}
*/
#include "libft.h"

static size_t	ft_strcount(const char *s, char c)
{
	size_t	count;

	count = 1;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
		while (*s != '\0' && *s == c)
			s++;
	}
	return (count);
}

static size_t	ft_lenchr(char const *s, size_t start, char c)
{
	size_t	i;

	i = 0;
	while (s[start + i] != c && s[start + i] != '\0')
		i++;
	return (i);
}

static	int	ft_setstrs(char **arr, char const *s, size_t count, char c)
{
	size_t	i_s;
	size_t	i_arr;
	size_t	len_str;

	i_s = 0;
	i_arr = 0;
	while (i_arr < count - 1)
	{
		while (s[i_s] == c)
			i_s++;
		len_str = ft_lenchr(s, i_s, c) + 1;
		arr[i_arr] = (char *)ft_calloc(len_str, sizeof(char));
		if (!arr[i_arr])
			return (0);
		ft_strlcpy(arr[i_arr], s + i_s, len_str);
		i_s = i_s + len_str;
		i_arr++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	str_count;

	if (!s)
		return (0);
	str_count = ft_strcount(s, c);
	arr = (char **)ft_calloc(str_count, sizeof(char *));
	if (arr)
	{
		if (ft_setstrs(arr, s, str_count, c))
			return (arr);
	}
	free(arr);
	return (0);
}
