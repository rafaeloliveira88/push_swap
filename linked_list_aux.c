/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:58:49 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/08 13:41:13 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_dlstclear(t_dlst **lst, void (*del)(void *))
{
	t_dlst	*current;
	t_dlst	*next;

	current = *lst;
	if (!current || !del)
		return ;
	while (current)
	{
		next = current->next;
		ft_dlstdelone(current, (*del));
		current = next;
	}
	*lst = NULL;
}

void	ft_dlstdelone(t_dlst *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}
