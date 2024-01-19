/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:18:33 by cde-migu          #+#    #+#             */
/*   Updated: 2024/01/19 12:15:08 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**total_ptr;
	char	*ptr_s1;
	char	*ptr_s2;
	int		i;

	ptr_s2 = (char *)malloc(ft_strlen(ft_strchr(s,c)) * sizeof(char));
	ptr_s2 = ft_strchr(s, c);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		 
		i++;
	}
	
}
