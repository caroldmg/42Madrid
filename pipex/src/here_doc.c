/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:21:37 by cde-migu          #+#    #+#             */
/*   Updated: 2024/12/05 18:30:58 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	ft_write_here_doc(int infile, char *limit)
{
	int 	read_bytes;
	char	buf[1024];

	while (1)
	{
		write(1, ">", 1);
		read_bytes = read(STDIN_FILENO, buf, 1024);
		if (read_bytes == 0)
			break ;
		else if (read_bytes < 0)
		{
			close(infile);
			return (1);
		}
		if (ft_strncmp(ft_new_limit(limit), buf, read_bytes) == 0)
			break ;
		write(infile, buf, read_bytes);
	}
	close(infile);
	return (0);
}

void	create_here_doc(char *limit)
{
	if (ft_write_heredoc("here_doc", limit))
	{
		perror("Error writing here_doc");
		exit(EXIT_FAILURE);
	}
}
int	open_here_doc(void)
{
	 int infile = open("here_doc", O_RDONLY);
    if (infile < 0)
    {
        perror("open here_doc");
        exit(EXIT_FAILURE);
    }
    return infile;
}

void	here_doc(char *limit, int argc)
{
	int	infile;

    if (argc < 6)
        ft_usage();
    create_here_doc_file(limit);
    infile = open_here_doc_file();
    dup2(infile, STDIN_FILENO);
    close(infile);
}
