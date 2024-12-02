/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:56:19 by cde-migu          #+#    #+#             */
/*   Updated: 2024/12/02 19:25:56 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		len = ft_strlen_gnl(*str) + 1;
	new = (char *)malloc((len) * sizeof(char));
	if (!new)
		return (free_null(str));
	ft_gnlstrlcpy(new, *str, len);
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
	len = ft_strlen_gnl(*str) - i;
	new = (char *)malloc((len) * sizeof(char));
	if (!new)
		return (free_null(str));
	ft_gnlstrlcpy(new, *str + i + 1, len);
	free_null(str);
	return (new);
}

static char	*read_and_append(int fd, char **buf)
{
	char		*content;
	ssize_t		read_bytes;

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
		*buf = ft_gnljoin(*buf, content);
		if (!*buf)
			return (NULL);
	}
	free_null(&content);
	return (*buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*content;
	ssize_t		read_bytes;

	read_bytes = 1;
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buf = read_and_append(fd, &buf);
	if (!buf)
		return (NULL);
	if (buf && buf[0] == '\0')
		return (free_null(&buf));
	content = fill_line(&buf);
	if (!content)
		return (NULL);
	buf = create_substr(&buf);
	if (!buf)
		return (free_null(&content));
	return (content);
}

/* int	main(void)
{
	int		fd;
	char	*content = "";
	int		i;

	i = 0;
	fd = open("only-nl.txt", O_RDONLY);
	while (content)
	{
		content = get_next_line(fd);
		printf("%s", content);
		i++;
		free(content);
	}
	close(fd);
	fd = open("get_next_line.h", O_RDONLY);
	content =  "";
	while (content)
	{
		content = get_next_line(fd);
		printf("%s", content);
		i++;
		free(content);
	}
	close(fd);
	//system("leaks a.out");
	return (0);
} */
