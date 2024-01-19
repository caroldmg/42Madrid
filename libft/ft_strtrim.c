/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:31:32 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/19 11:27:44 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*trim_helper(char *s1, char *set, char *ptr)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				j++;
			else
				ptr = ft_strchr(s1, s1[i]);
		}
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = (char *)malloc(ft_strlen(s1) * sizeof(char));
	if (ptr)
	{
		ptr = trim_helper(s1, set, ptr);
		i = ft_strlen(ptr) - 1;
		while (ptr[i] != '\0')
		{
			j = 0;
			while (set[j] != '\0')
			{
				if (ptr[i] == set[j])
					j++;
				else
					ptr[i] = '\0';
			}
			i--;
		}
		return (ptr);
	}
	return (0);
}
