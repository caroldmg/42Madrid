/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:06:27 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/27 11:50:40 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	len_to_linebreak(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static char	*fill_line(char **str)
{
	char	*new;
	size_t	len;

	if (ft_findnchar(*str))
		len = len_to_linebreak(*str) + 2;
	else
		len = ft_strlen(*str) + 1;
	new = (char *)malloc((len) * sizeof(char));
	if (!new)
		return (free_null(str));
	ft_strlcpy(new, *str, len);
	return (new);
}

static char	*create_substr(char **str)
{
	int		i;
	char	*new;
	size_t	len;

	i = 0;
	if (!*str)
		return (NULL);
	i = len_to_linebreak(*str);
	len = ft_strlen(*str) - i;
	new = (char *)malloc((len) * sizeof(char));
	if (!new)
		return (free_null(str));
	ft_strlcpy(new, *str + i + 1, len);
	free_null(str);
	return (new);
}

static char	*read_and_append(int fd, char **buf)
{
	char	*content;
	ssize_t	read_bytes;

	read_bytes = 1;
	content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!content)
		return (free_null(buf), NULL);
	content[0] = '\0';
	while (!ft_findnchar(content) && read_bytes > 0)
	{
		read_bytes = read(fd, content, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free_null(buf), free_null(&content));
		content[read_bytes] = '\0';
		*buf = ft_strjoin(*buf, content);
		if (!*buf)
			return (NULL);
	}
	free_null(&content);
	return (*buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*content;
	ssize_t		read_bytes;

	read_bytes = 1;
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd > OPEN_MAX)
		return (NULL);
	buf[fd] = read_and_append(fd, &buf[fd]);
	if (!buf[fd])
		return (free_null(&buf[fd]));
	if (buf[fd] && buf[fd][0] == '\0')
		return (free_null(&buf[fd]));
	content = fill_line(&buf[fd]);
	if (!content)
		return (free_null(&buf[fd]));
	buf[fd] = create_substr(&buf[fd]);
	if (!buf[fd])
		return (free_null(&content));
	return (content);
}
/* int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		l;

	for (int i = 1; i < argc; i++)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			return (0);
		l = 1;
		printf("Get_Next_Line de: %s \n", argv[i]);
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
			{
				printf("\nFin del fichero\n");
				break ;
			}
			printf("[%d]: %s", l, line);
			l++;
		}
		close(fd);
	}
	return (0);
}
 */