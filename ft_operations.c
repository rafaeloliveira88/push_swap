/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:41:23 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/26 18:25:41 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_lsti **lst, int stack, int print_command)
{
	int	temp;

	if (*lst && ft_lstisize(*lst) > 1)
	{
		if (*lst && ft_lstisize(*lst) > 1)
		{
			temp = (*lst)->c;
			(*lst)->c = (*lst)->n->c;
			(*lst)->n->c = temp;
		}
	}
	if (print_command)
	{
		if (stack == 0)
			ft_print_command(0);
		else
			ft_print_command(1);
	}
}

void	ft_swapall(t_lsti **lst_x, t_lsti **lst_y, int print_command)
{
	int	temp;

	if (*lst_x && ft_lstisize(*lst_x) > 1)
	{
		if (*lst_x && ft_lstisize(*lst_x) > 1)
		{
			temp = (*lst_x)->c;
			(*lst_x)->c = (*lst_x)->n->c;
			(*lst_x)->n->c = temp;
		}
	}
	if (*lst_y && ft_lstisize(*lst_y) > 1)
	{
		if (*lst_y && ft_lstisize(*lst_y) > 1)
		{
			temp = (*lst_y)->c;
			(*lst_y)->c = (*lst_y)->n->c;
			(*lst_y)->n->c = temp;
		}
	}
	if (print_command)
		ft_print_command(2);
}

void	ft_rotate(t_lsti **lst, int stack, int print_command)
{
	if (ft_lstisize(*lst) > 1)
		(*lst) = (*lst)->n;
	if (print_command)
	{
		if (stack == 0)
			ft_print_command(5);
		else
			ft_print_command(6);
	}
}

void	ft_rotateall(t_lsti **lst_x, t_lsti **lst_y, int print_command)
{
	if (ft_lstisize(*lst_x) > 1)
		(*lst_x) = (*lst_x)->n;
	if (ft_lstisize(*lst_y) > 1)
		(*lst_y) = (*lst_y)->n;
	if (print_command)
		ft_print_command(7);
}

void	ft_rrotate(t_lsti **lst, int stack, int print_command)
{
	if (ft_lstisize(*lst) > 1)
		(*lst) = (*lst)->p;
	if (print_command)
	{
		if (stack == 0)
			ft_print_command(8);
		else
			ft_print_command(9);
	}
}
