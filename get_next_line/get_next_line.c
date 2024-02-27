/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:00:01 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/27 12:03:34 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// essta función debería contar cuántas strings de tamaño buff_size habrá que crear para almacenar el espacio hasta el salto de línea
size_t	count_str(int fd, int buff_size)
{
	size_t c;
	int	r;
	char	buf[buff_size];
	
	r = read(fd, buf, buff_size);
	while ( c && c != '\n')
	{
		r = read(fd, buf, buff_size);
		c++;
	}
	return (c);
}
//para guardar las strings 
char *save_str(int buff_size, char **arr_buff, int fd, size_t count)
{
	char	*str;
	int		i;

	str = (char *)malloc((buff_size + 1)* sizeof(char));
	str = read(fd, str, buff_size);
	return (str);
}

char *find_next_line(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
}

char *get_next_line(int fd)
{
	//buffer tendrá que ser una variable estática
	int		buff_size;
	buff_size = 20;
	char	**arr_buff;
	size_t	count;

	count = count_str(fd, buff_size);
	arr_buff = (char **)malloc(count * sizeof(char *));
	if (!arr_buff)
		return (0);
	
}