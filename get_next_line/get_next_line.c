/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:56:19 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/25 19:13:54 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	len_to_linebreak(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static char	*fill_line(char *str)
{
	char	*new;
	size_t	len;

	if (ft_findnchar(str))
		len = len_to_linebreak(str) + 2;
	else
		len = ft_strlen(str) + 1;
	new = (char *)malloc((len) * sizeof(char));
	if (!new)
		return (free_null(&str));
	ft_strlcpy(new, str, len);
	return (new);
}

static char	*create_substr(char *str)
{
	int		i;
	char	*new;
	size_t	len;

	i = 0;
	if (!str)
		return (NULL);
	i = len_to_linebreak(str);
	len = ft_strlen(str) - i;
	new = (char *)malloc((len) * sizeof(char));
	if (!new)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	ft_strlcpy(new, str + i + 1, len);
	free(str);
	str = NULL;
	return (new);
}

static char	*read_and_append(int fd, char *buf)
{
	char		*content;
	ssize_t		read_bytes;

	read_bytes = 1;
	content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!content)
		return (NULL);
	content[0] = '\0';
	while (!ft_findnchar(content) && read_bytes > 0)
	{
		read_bytes = read(fd, content, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free_null(&content), free_null(&buf));
		content[read_bytes] = '\0';
		buf = ft_strjoin(buf, content);
		if (!buf)
			return (NULL);
	}
	free_null(&content);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*content;
	ssize_t		read_bytes;

	read_bytes = 1;
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buf = read_and_append(fd, buf);
	if (!buf)
		return (NULL);
	if (buf && buf[0] == '\0')
		return (free_null(&buf));
	content = fill_line(buf);
	if (!content)
		return (free_null(&buf));
	buf = create_substr(buf);
	if (!buf)
		return (free_null(&content));
	return (content);
}

int	main(void)
{
	int		fd;
	char	*content = "";
	int		i;

	i = 0;
	fd = 0;//open("1char_nl.txt", O_RDONLY);
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
}
