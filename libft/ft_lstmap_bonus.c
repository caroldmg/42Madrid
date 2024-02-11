/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:42:23 by cde-migu          #+#    #+#             */
/*   Updated: 2024/02/11 17:29:21 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*current;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	current = lst;
	while (current != NULL)
	{
		result = ft_lstnew(f(current->content));
		if (!result)
		{
			result = current->next;
			del(current->content);
			free(current);
			return (NULL);
		}
		current = current->next;
	}
	return (result);
}
