/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:53:25 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 12:14:15 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates the list ’lst’ and applies the function
** ’f’ on the content of each node. Creates a new
** list resulting of the successive applications of
** the function ’f’. The ’del’ function is used to
** delete the content of a node if needed.
** -------------------------------------------------------
** lst: The address of a pointer to a node.
** f: The address of the function used to iterate on
** the list.
** del: The address of the function used to delete
** the content of a node if needed.
** -------------------------------------------------------
** The new list.
** NULL if the allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (lst == NULL || (*f) == NULL || (*del) == NULL)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		if (!content)
			return (ft_lstclear(&new_list, (*del)), (NULL));
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			(*del)(content);
			ft_lstclear(&new_list, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
