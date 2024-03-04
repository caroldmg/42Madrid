/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:53:40 by cde-migu          #+#    #+#             */
/*   Updated: 2024/03/04 15:04:17 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
}
