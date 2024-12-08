/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:58:24 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/08 16:24:14 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst				*ft_dlstnew(void *content)
{
    t_dlst *new;
    
    new = (t_dlst *) malloc(sizeof(t_dlst));
    if(!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    new->prev = NULL;
}

void				ft_dlstadd_front(t_dlst **lst, t_dlst *new_node)
{
    if(new_node)
    {
        if(!(*lst))
            *lst = new_node;
        else
        {
            new_node->prev = ft_dlstlast(*lst);
            (*lst)->prev = new_node;
            new_node->next = (*lst);
            ft_dlstlast(*lst)->next = new_node;
            (*lst) = new_node;
        }
    }
}

t_dlst				*ft_dlstlast(t_dlst *lst)
{
    t_dlst *first;

    first = lst;
    while(lst && lst->next && (lst->next) != first)
    {
        lst = lst->next;
    }
    return (lst);
}

int					ft_dlstsize(t_dlst *lst)
{
    int i;
    t_dlst *first;

    i = 0;
    first = lst;
    while(lst && lst->next != first)
    {
        i++;
        lst = lst->next;
    }
    if(lst && lst->next == first)
        i++;
    return (i);
}

t_dlst  *ft_dlstpush(t_dlst **lst)
{
    t_dlst *first;
    t_dlst *last;

    if(*lst)
    {
        if(ft_dlstsize(*lst) == 1)
        {
            first = *lst;
            *lst = NULL;
        }
        else{
            first = *lst;
            last = (*lst)->prev;
            *lst = (*lst)->next;
            (*lst)->prev = first->prev;
            last->next = *lst;
            
        }
        first->next = NULL;
        first->prev = NULL;
        return (first);
    }
    return (NULL);
}
