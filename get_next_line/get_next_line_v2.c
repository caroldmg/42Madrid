/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:00:01 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/28 15:25:19 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//JOIN VERSION
size_t	ft_strlen(const char *s)
{
	size_t	strlen;

	strlen = 0;
	while (*s != '\0')
	{
		strlen++;
		s++;
	}
	return (strlen);
}

int	find_next_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	//buffer tendrá que ser una variable estática
	static char	*total_str;
	//crear la primera str
	total_str = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char *));
	if (!total_str)
		return (0);
	
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	total_len;

	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(total_len * sizeof(char));
	if (new)
	{
		ft_strlcpy(new, s1, ft_strlen(s1) + 1);
		ft_strlcat(new, s2, total_len);
		new[total_len - 1] = '\0';
		return (new);
	}
	else
		return (0);
}