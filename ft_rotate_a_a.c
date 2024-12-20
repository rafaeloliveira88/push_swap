/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:54:54 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/20 12:03:02 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_choose_rot_a_aux(t_data_container *dc, int ind, int r, t_lsti **cmds)
{
	int j;
	int size;

	size = ft_lstisize(dc->a);
	j = 0;
	if(r == 0) //rotate
	{
		while(j < ind)
		{
			ft_rotate(&dc->a, 0, 0);
			ft_lstiadd_last(cmds, ft_lstinew(5));
			j++;
		}
	}
	else //reverse rotate
	{
		while(ind < size)
		{
			ft_rrotate(&dc->a, 0, 0);
			ft_lstiadd_last(cmds, ft_lstinew(8));
			ind++;
		}
	}
}

void ft_choose_rot_a_aux_middle(t_data_container *dc, int ind, t_lsti **cmds)
{
	int j;
	
	j = 0;

	while(j < ind)
	{
		ft_rotate(&dc->a, 0, 0);
		ft_lstiadd_last(cmds, ft_lstinew(11));
		j++;
	}
}

t_lsti	*ft_choose_rotate_a(t_data_container *dc, int index)
{
	t_lsti	*commands;
	int size;
	int i;

	commands = NULL;
	size = ft_lstisize(dc->a);
	i = 0;
	//the number is in the middle of stack 
	if((size%2) == 0 && (size / 2) == index ) 
	{
		ft_choose_rot_a_aux_middle(dc, index, &commands);
	}
	else
	{
		if(index <= (size/2))// first middle part
			ft_choose_rot_a_aux(dc, index, 0, &commands);
		else //after middle part
			ft_choose_rot_a_aux(dc, index, 1, &commands);
	}
	return (commands);
}

int ft_rot_a_between_min_max(t_data_container *dc)
{
	int i;
	int j;
	t_lsti *a;

	a = dc->a;
	i = 0;
	j = 0;
	while(!(dc->b->c > dc->a->p->c && dc->b->c < dc->a->c))
	{
		ft_rotate(&dc->a,0,0);
		i++;
	}
	dc->a = a;
	while(!(dc->b->c > dc->a->p->c && dc->b->c < dc->a->c))
	{
		ft_rrotate(&dc->a,0,0);
		j++;
	}
	dc->a = a;
	while(!(dc->b->c > dc->a->p->c && dc->b->c < dc->a->c))
		if(i<=j)
			ft_rotate(&dc->a,0,1);
		else
			ft_rrotate(&dc->a,0,1);
}

void ft_rot_a_min_top(t_data_container *dc)
{
	int i;
	int j;
	t_lsti *a;

	a = dc->a;
	i = 0;
	j = 0;
	while(dc->a->c != dc->min)
	{
		ft_rotate(&dc->a,0,0);
		i++;
	}
	dc->a = a;
	while(dc->a->c != dc->min)
	{
		ft_rrotate(&dc->a,0,0);
		j++;
	}
	dc->a = a;
	while(dc->a->c != dc->min)
		if(i<j)
			ft_rotate(&dc->a,0,1);
		else
			ft_rrotate(&dc->a,0,1);
}
