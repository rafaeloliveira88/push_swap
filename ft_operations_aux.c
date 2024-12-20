/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:42:09 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/20 12:05:27 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotateall(t_lsti **lst_x, t_lsti **lst_y, int print_command)
{
	if (ft_lstisize(*lst_x) > 1)
	{
		(*lst_x) = (*lst_x)->p;
	}
	if (ft_lstisize(*lst_y) > 1)
	{
		(*lst_y) = (*lst_y)->p;
	}
	if (print_command)
		ft_print_command(10);
}

void	ft_push(t_lsti **lst_x, t_lsti **lst_y, int stack, int print_command)
{
	t_lsti	*node;

	if ((*lst_x))
	{
		node = ft_lstipush(lst_x);
		ft_lstiadd_front(lst_y, node);
	}
	if (print_command)
	{
		if (stack == 0)
			ft_print_command(3);
		else
			ft_print_command(4);
	}
}
