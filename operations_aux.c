/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operantions_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:42:09 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/08 16:44:07 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rrotateall(t_dlst **lst_x, t_dlst **lst_y)
{
    if(ft_dlstsize(*lst_x) > 1)
    {
       (*lst_x) = (*lst_x)->prev;
    }
    if(ft_dlstsize(*lst_y) > 1)
    {
       (*lst_y) = (*lst_y)->prev;
    }
}

void ft_push(t_dlst **lst_x, t_dlst **lst_y)
{
    t_dlst *node;
    
    if((*lst_x))
    {
        node = ft_dlstpush(lst_x);
        ft_dlstadd_front(lst_y, node);
    }
}