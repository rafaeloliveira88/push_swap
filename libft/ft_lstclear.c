/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:31:12 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 15:39:50 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Deletes and frees the given node and every
** successor of that node, using the function ’del’
** and	free.
** Finally, the pointer to the list must be set to
** NULL.
*** ----------------------------------------------------
** lst: The address of a pointer to a node.
** del: The address of the function used to delete
** the content of the node.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	if (current == NULL || del == NULL)
		return ;
	while (current != NULL)
	{
		next = current->next;
		ft_lstdelone(current, (*del));
		current = next;
	}
	*lst = NULL;
}
