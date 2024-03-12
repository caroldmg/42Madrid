/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:53:40 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/12 15:02:32 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_null(char *s1, char *s2)
{
	free(s1);
	free(s2);
	s2 = NULL;
	return (s2);
}

static int	len_to_linebreak(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static char	*read_line(char *str)
{
	char	*new;
	int		len;

	len = len_to_linebreak(str);
	//printf("len --> (dentro de read_line) %d \n", len);
	new = (char *)malloc((len + 2) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, str, len + 2);
	//printf("Longitud de string creada en read_line -->%d \n", ft_strlen(new));
/* 	int i = 0;
	while (new[i])
	{
		printf("%c", new[i]);
		i++;
	} */
	return (new);
}
static char	*create_substr(char *str)
{
	int i;
	char	*new;
	size_t	len;

	i = 0;
	if (!str)
	{
	//	free(str);
		return (NULL);
	}
	i = len_to_linebreak(str);
	len = ft_strlen(str) - i;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(new, str + i + 1, len + 1);
	free(str);
	return (new);
}

char *get_next_line(int fd)
{
	static char	*buf;
	char		*content;
	ssize_t		read_bytes;

	read_bytes = 1;
	if (fd == -1 || BUFFER_SIZE == 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!content)
		return (NULL);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, content, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			buf = free_null(content, buf);
			return (NULL);
		}
		*(content + read_bytes) = '\0';
		buf = ft_strjoin(buf, content);
	}
	free(content);
	content = read_line(buf);
	printf("static----> %s\n", buf);
	buf = create_substr(buf);
	return (content);
}