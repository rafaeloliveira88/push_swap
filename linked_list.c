/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:58:24 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/12 18:49:36 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstnew(void *content)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->c = content;
	new->n = NULL;
	new->p = NULL;
	return (new);
}

void	ft_lstadd_front(t_lst **lst, t_lst *new_node)
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
			(*lst) = new_node;
		}
	}
}

t_lst	*ft_lstlast(t_lst *lst)
{
	t_lst	*first;

	first = lst;
	while (lst && lst->n && (lst->n) != first)
	{
		lst = lst->n;
	}
	return (lst);
}

int	ft_lstsize(t_lst *lst)
{
	int		i;
	t_lst	*first;

	i = 0;
	first = lst;
	while (lst && lst->n != first)
	{
		i++;
		lst = lst->n;
	}
	if (lst && lst->n == first)
		i++;
	return (i);
}

t_lst	*ft_lstpush(t_lst **lst)
{
	t_lst	*first;
	t_lst	*last;

	if (*lst)
	{
		if (ft_lstsize(*lst) == 1)
		{
			first = *lst;
			*lst = NULL;
		}
		else
		{
			first = *lst;
			last = (*lst)->p;
			*lst = (*lst)->n;
			(*lst)->p = first->p;
			last->n = *lst;
		}
		first->n = NULL;
		first->p = NULL;
		return (first);
	}
	return (NULL);
}
