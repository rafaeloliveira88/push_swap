/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:58:49 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/20 13:38:56 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_lst **lst, void (*del)(void *))
{
	t_lst	*current;
	t_lst	*next;
	int		i;
	int		size;
	t_lsti *aux;

	i = 0;
	current = *lst;
	if (!current)
		return ;
	size = ft_lstsize(*lst);
	while (i < size)
	{
		next = current->n;
		aux = current->c; 
		ft_lsticlear(&aux);
		free(current);
		current = next;
		i++;
	}
	*lst = NULL;
}

void	ft_lstdelone(t_lst *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->c);
	free(lst);
}

void	ft_free_integer(void *content)
{
	(void)content;
}

void	ft_lstadd_last(t_lst **lst, t_lst *new_node)
{
	if (new_node)
	{
		if (!(*lst))
			*lst = new_node;
		else
		{
			new_node->p = ft_lstlast(*lst);
			(*lst)->p = new_node;
			new_node->n = (*lst);
			ft_lstlast(*lst)->n = new_node;
		}
	}
}
