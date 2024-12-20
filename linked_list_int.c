/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:58:24 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/12 18:49:25 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lsti	*ft_lstinew(int content)
{
	t_lsti	*new;

	new = (t_lsti *)malloc(sizeof(t_lsti));
	if (!new)
		return (NULL);
	new->c = content;
	new->n = NULL;
	new->p = NULL;
	return (new);
}

void	ft_lstiadd_front(t_lsti **lst, t_lsti *new_node)
{
	if (new_node)
	{
		if (!(*lst))
			*lst = new_node;
		else
		{
			new_node->p = ft_lstilast(*lst);
			(*lst)->p = new_node;
			new_node->n = (*lst);
			ft_lstilast(*lst)->n = new_node;
			(*lst) = new_node;
		}
	}
}

t_lsti	*ft_lstilast(t_lsti *lst)
{
	t_lsti	*first;

	first = lst;
	while (lst && lst->n && (lst->n) != first)
	{
		lst = lst->n;
	}
	return (lst);
}

int	ft_lstisize(t_lsti *lst)
{
	int		i;
	t_lsti	*first;

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

t_lsti	*ft_lstipush(t_lsti **lst)
{
	t_lsti	*first;
	t_lsti	*last;

	if (*lst)
	{
		if (ft_lstisize(*lst) == 1)
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
