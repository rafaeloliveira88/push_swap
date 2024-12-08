/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:08:49 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 12:11:53 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds the node ’new’ at the end of the list.
** -------------------------------------------------
** lst: The address of a pointer to the first link of
** a list.
** new: The address of a pointer to the node to be
** added to the list.
--------------------------------------------------
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (new == NULL)
		return ;
	node = *lst;
	if (node == NULL)
		*lst = new;
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
}
