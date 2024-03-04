/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:00:01 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/04 15:02:58 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//JOIN VERSION

int	find_next_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static char	*ft_strjoin(char *s1, char *s2, int len_s2)
{
	char	*new;
	size_t	total_len;

	if (!len_s2)
		len_s2 = ft_strlen(s2);
	total_len = ft_strlen(s1) + len_s2 + 1;
	new = (char *)malloc(total_len * sizeof(char));
	if (!new)
		return (0);
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcat(new, s2, total_len);
	new[total_len - 1] = '\0';
	free(s1);
	return (new);
}

static int new_str(char *str, int size)
{
	if(str)
	{
		free(str);
		return (1);
	}
	else
	{
		str = (char *)malloc((size + 1) * sizeof(char *));
		if (!str)
			return (0);
		return (1);
	}
}
static char *store_rest(char *str, int fd, int len_to_n)
{
	char  *store;

	if (!str || !fd || len_to_n <= 0)
		return (0);
	if (len_to_n != BUFFER_SIZE)
	{
		store = (char *)malloc((BUFFER_SIZE - len_to_n + 1) * sizeof(char));
		if (!store)
			return (0);
		read(fd, store, len_to_n);
	}
	else
	{
		store = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!store)
			return (0);
		read(fd, store, len_to_n);
	}
	if (store)
		return (store);
	else
		return (0);
}

char *get_next_line(int fd)
{
	static char	*total_str;
	static char	*store;
	static int	store_len;
	char	*s2;
	
	s2 = NULL;
	if (store)
		new_str(store, store_len);
	else
		new_str(total_str, BUFFER_SIZE);
	if (!total_str || fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	while (read(fd, s2, BUFFER_SIZE))
	{
		if (find_next_line(s2))
		{
			store_len = find_next_line(s2);
			store = store_rest(s2, fd, store_len);
			total_str = ft_strjoin(total_str, s2, find_next_line(s2));
			break;
		}
		total_str = ft_strjoin(total_str, s2, 0);
	}
	return (total_str);
}
