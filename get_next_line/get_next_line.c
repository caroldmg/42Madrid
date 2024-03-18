/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:56:19 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/18 20:14:45 by cde-migu         ###   ########.fr       */
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

static char	*read_line(char *str)
{
	char	*new;
	size_t	len;

	len = len_to_linebreak(str);
	new = (char *)malloc((len + 2) * sizeof(char));
	if (!new)
		return (free(str), NULL);
	ft_strlcpy(new, str, len + 2);
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
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	ft_strlcpy(new, str + i + 1, len + 1);
	free(str);
	str = NULL;
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*content;
	char		*help;
	ssize_t		read_bytes;

	read_bytes = 1;
	if (read(fd, 0, 0) || BUFFER_SIZE == 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	content = NULL;
	help = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!help)
		return (NULL);
	help[0] = '\0';
	//ft_memset(help, 0, BUFFER_SIZE + 1);
	while (!ft_findnchar(help) && read_bytes > 0)
	{
		read_bytes = read(fd, help, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(help);
			free(buf);
			return (NULL);
		}
		help[read_bytes] = '\0';
		buf = ft_strjoin(buf, help);
		if (!buf)
			return (free(help), NULL);
	}
	free(help);
	if (buf && buf[0] == '\0')
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	content = read_line(buf);
	if (!content)
		return (NULL);
	buf = create_substr(buf);
	if (!buf)
		return (free(content), NULL);
	return (content);
}

/* int	main(void)
{
	int		fd;
	char	*content;
	int		i;

	i = 0;
	fd = open("TEXTO.txt", O_RDONLY);
	while (i < 50)
	{
		content = get_next_line(fd);
		printf("%s", content);
		i++;
	}
	free(content);
	close(fd);
	//system("leaks a.out");
	return (0);
} */
