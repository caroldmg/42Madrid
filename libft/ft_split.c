/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:18:33 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/29 11:38:50 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*onlynull(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(char));
	if (!str)
		return (0);
	str[0] = 0;
	return (str);
}

static char *create_str(char *start, int len)
{
	
}


static	size_t	count_strings(char const *s, char c)
{
	size_t	count;
	int		i;
	char	*str;

	count = 0;
	str = (char)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			create_str(str[i + 1], i);
			count++;
			str++;
			i = 0;
		}
		i++;
	}
}
char	**ft_split(char const *s, char c)
{
	char	**total_ptr;
	int		i;

	total_ptr = (char **) malloc (2 * sizeof(char *));
	total_ptr[1] = (char *) malloc(ft_strlen(ft_strchr(s,c)) * sizeof(char));
	total_ptr[1] = ft_strchr(s, c);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	total_ptr[0] = (char *)malloc(i * sizeof(char));
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		total_ptr[0][i] = s[i];
		i++;
	}
	return (total_ptr);
}