/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:53:40 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/05 16:30:32 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_new_line(char *str, int i)
{
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static char	*create_substring(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i = find_new_line(str, i);
	new = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!new)
	{
		free(new);
		return (NULL);
	}
	ft_strlcpy(new, str + i, (ft_strlen(str) - i + 1));
	if (!*new)
	{
		free(str);
		free(new);
		return (NULL);
	}
	free(str);
	return (new);
}

static char	*read_line(char *str)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	if (!str)
		return (NULL);
	i = find_new_line(str, i);
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, str, i + 1);
	return (line);
}
static char	*free_null(char *s1, char *s2)
{
	free(s1);
	free(s2);
	s2 = NULL;
	return (s2);
}

char	*get_next_line(int fd)
{
	static char	*read_buf;
	char		*content;
	int			read_bytes;

	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!content)
		return (NULL);
	while (!ft_findnchar(read_buf) && read_bytes)
	{
		read_bytes = read(fd, content, BUFFER_SIZE);
		if (!read_bytes)
		{
			read_buf = free_null(content, read_buf);
			return (NULL);
		}
		*(content + read_bytes) = '\0';
		read_buf = ft_strjoin(read_buf, content);
	}
	free(content);
	content = read_line(read_buf);
	read_buf = create_substring(read_buf);
	return (content);
}

/* int main(void)
{
	int file_descriptor = open("example.txt", O_RDONLY);
	char* line = get_next_line(file_descriptor);

	// Process the line

	// Free the memory allocated for the line
	free(line);

	close(file_descriptor);
	return (0);
} */