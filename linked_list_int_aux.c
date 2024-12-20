/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_int_aux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:58:49 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/18 12:07:36 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_lsticlear(t_lsti **lst)
{
	t_lsti	*current;
	t_lsti	*next;
	int i;
	int size;
	
	current = *lst;
	i = 0;
	if (!current)
		return ;
	size = ft_lstisize(*lst);
	while (i < size)
	{
		next = current->n;
		ft_lstidelone(current);
		current = next;
		i++;
	}
	*lst = NULL;
}

void	ft_lstidelone(t_lsti *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void				ft_lstiadd_last(t_lsti **lst, t_lsti *new_node)
{
    if(new_node)
    {
        if(!(*lst))
            *lst = new_node;
        else
        {
            new_node->p = ft_lstilast(*lst);
            (*lst)->p = new_node;
            new_node->n = (*lst);
            ft_lstilast(*lst)->n = new_node;
        }
    }
}