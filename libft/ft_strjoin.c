/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:02:56 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/19 11:29:01 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char));
	if (ptr)
	{
		i = 0;
		j = 0;
		while (s1[i] != '\0')
			ptr[j++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			ptr[j++] = s2[i++];
		ptr[j] = '\0';
		return (ptr);
	}
	else
		return (0);
}
