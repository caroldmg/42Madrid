/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:31:35 by cde-migu          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/04 17:07:27 by cde-migu         ###   ########.fr       */
=======
/*   Updated: 2024/02/11 18:24:19 by cde-migu         ###   ########.fr       */
>>>>>>> b2ea680ad5fb6d10b9159efd9d6fbf4ed97bdde4
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
<<<<<<< HEAD
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
=======
	if (!lst && !new)
		return ;
	new->next = *lst;
	*lst = new;
>>>>>>> b2ea680ad5fb6d10b9159efd9d6fbf4ed97bdde4
}
