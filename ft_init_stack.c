/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:27:07 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/20 11:32:33 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_exist(t_lsti *lst, t_lsti *node)
{
    t_lsti *curr;
    int i;
    int size;
    
    curr = lst;
    i = 0;
    size = ft_lstisize(lst);
    while(i < size)
    {
        if(curr->c == node->c)
            return (1);
        curr = curr->n;
        i++;
    }
    return (0);
}

t_lsti *ft_init_stack_a(int size,char **args)
{
    t_lsti *a;

    a = NULL;
    while(size-- != 1)
    {
        t_lsti *x = ft_lstinew(ft_atoi(args[size]));
        if(!x)
        {
            ft_lsticlear(&a);
            return (NULL);
        }
        else
        {
            if(ft_check_exist(a, x) == 0)
                ft_lstiadd_front(&a, x);
            else
            {
                ft_lsticlear(&a); 
                return (NULL);
            }
        }
    }
    return (a);
}
