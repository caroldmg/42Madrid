/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:21:37 by cde-migu          #+#    #+#             */
/*   Updated: 2024/12/05 12:42:19 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* void	here_doc(char *limit, int argc)
{
	char	*line;
	int		infile;
	(void)argc;

	infile = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	while (1)
	{
		line = get_next_line(READ_E);
		close(infile);
		close(READ_E);
		if (ft_strcmp(line, limit) != 0)
			write(infile, line, ft_strlen(line));
		else
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		free(line);
	}
} */

char	*ft_new_limit(char *limit)
{
	size_t	limit_len;
	char	*new_limit;

	limit_len = ft_strlen(limit);
	new_limit = malloc(limit_len + 2);
	ft_strlcpy(new_limit, limit, limit_len + 1);
	new_limit[limit_len] = '\n';
	new_limit[limit_len + 1] = '\0';
	return (new_limit);
}

int	ft_write_heredoc(int infile, char *limit)
{
	int 	read_bytes;
	char	buf[1024];

	while (1)
	{
		write(1, ">", 1);
		read_bytes = read(STDIN_FILENO, buf, 1024);
		if (read_bytes == 0)
			break;
		else if (read_bytes < 0)
		{
			close(infile);
			return (1);
		}
		if (!ft_strcmp(ft_new_limit(limit), buf))
			break;
		write(infile, buf, read_bytes);
	}
	return (0);
}

int	here_doc(int argc, char *limit)
{
	char	*line;
	int		infile;
	(void)argc;

	infile = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (infile < 0)
		perror("open: ");
	ft_write_heredoc(infile, limit);
}