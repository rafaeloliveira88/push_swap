/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:41:23 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/08 16:43:42 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(t_dlst **lst)
{
    void *temp;
    if(*lst && ft_dlstsize(*lst) > 1)
    {
        if(*lst && ft_dlstsize(*lst) > 1)
        {
            temp = (*lst)->content;
            (*lst)->content = (*lst)->next->content;
            (*lst)->next->content = temp;
        }
    }
}

void    ft_swapall(t_dlst **lst_x, t_dlst **lst_y)
{
    void *temp;
    if(*lst_x && ft_dlstsize(*lst_x) > 1)
    {
        if(*lst_x && ft_dlstsize(*lst_x) > 1)
        {
            temp = (*lst_x)->content;
            (*lst_x)->content = (*lst_x)->next->content;
            (*lst_x)->next->content = temp;
        }
    }
    if(*lst_y && ft_dlstsize(*lst_y) > 1)
    {
        if(*lst_y && ft_dlstsize(*lst_y) > 1)
        {
            temp = (*lst_y)->content;
            (*lst_y)->content = (*lst_y)->next->content;
            (*lst_y)->next->content = temp;
        }
    }
}

void    ft_rotate(t_dlst **lst)
{
    if(ft_dlstsize(*lst) > 1)
    {
       (*lst) = (*lst)->next;
    }
}

void    ft_rotateall(t_dlst **lst_x, t_dlst **lst_y)
{
    if(ft_dlstsize(*lst_x) > 1)
    {
       (*lst_x) = (*lst_x)->next;
    }
    if(ft_dlstsize(*lst_y) > 1)
    {
       (*lst_y) = (*lst_y)->next;
    }
}

void    ft_rrotate(t_dlst **lst)
{
    if(ft_dlstsize(*lst) > 1)
    {
       (*lst) = (*lst)->prev;
    }
}