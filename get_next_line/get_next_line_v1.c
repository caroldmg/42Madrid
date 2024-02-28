/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:00:01 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/28 11:40:36 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//SPLIT VERSION

// essta función debería contar cuántas strings de tamaño buff_size habrá que crear para almacenar el espacio hasta el salto de línea
size_t	count_str(int fd, int buff_size)
{
	size_t c;
	int	r;
	//revisar esto
	//char	buf[buff_size];
	char *buf;
	
	r = read(fd, buf, buff_size);
	while ( c && c != '\n')
	{
		r = read(fd, buf, buff_size);
		c++;
	}
	return (c);
}
//para guardar las strings 
static int save_str(int buff_size, char **arr_buff, int fd, size_t count)
{
	char	*str;
	size_t	i;

	i = 0;
	while (i < count)
	{
		str = (char *)malloc((buff_size + 1)* sizeof(char));
		if (!str)
		{
			while (i >= 0)
				free(arr_buff[i--]);
			return (0);
		}
		read(fd, str, buff_size);
		//falta contar si llega al \n
		arr_buff[i] = str;
		i++;
	}
	return (str);
}
int	find_next_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char *get_next_line(int fd)
{
	//buffer tendrá que ser una variable estática
	int		buff_size;
	buff_size = 20;
	char	**arr_buff;
	size_t	count;

	count = count_str(fd, buff_size);
	arr_buff = (char **)malloc(count + 1 * sizeof(char *));
	if (!arr_buff)
		return (0);
	
}