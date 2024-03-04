/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:53:40 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/04 17:45:37 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *create_substring(char *read_buf);
char *read_line(char *read_buf)
{
	
}
char *free_null(char *s1, char *s2)
{
	free(s1);
	free(s2);
	s2 = NULL;
	return (s2);
}

char *get_next_line(int fd)
{
	static char *read_buf;
	char *content;
	int read_bytes;
	
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
			//funcion que me vacíe s1 y s2, y me devuelva s2 con valor NULL
			read_buf = free_null(content, read_buf);
			return (NULL);
		}
		content[read_bytes] = '\0';
		read_buf = ft_strjoin(read_buf, content);
	}
	free(content);
	//meter en content la linea leida hasta \n
	content = read_line(read_buf);
	//desde \n hasta el final del espacio del buffer para no perder ese trocito
	read_buf = create_substring(read_buf);
	return (content);
}
