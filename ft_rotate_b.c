/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:48:08 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/20 11:22:31 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_rot_b_aux(t_data_container *dc, t_lsti **cmd, int rot)
{
	if(rot == 0)
	{
		while ((dc->b)->c != dc->max)
		{
			ft_rotate(&dc->b, 1, 0);
			ft_lstiadd_last(cmd, ft_lstinew(6));
		}
	}
	else
	{
		while ((dc->b)->c != dc->max)
		{
			ft_rrotate(&dc->b, 1, 0);
			ft_lstiadd_last(cmd, ft_lstinew(9));
		}
	}
}

void	ft_rotate_b_untill_top_max(t_data_container *dc, t_lsti **commands)
{	int i;
	int j;	
	t_lsti *b;
	
	b = dc->b;
	i = 0;
	j = 0;
	while ((dc->b)->c != dc->max)
	{
		ft_rotate(&dc->b, 1, 0);
		i++;
	}
	dc->b = b;
	while ((dc->b)->c != dc->max)
	{
		ft_rrotate(&dc->b, 1, 0);
		j++;
	}
	dc->b = b;
	if(i < j)
		ft_rot_b_aux(dc, commands, 0);
	else
		ft_rot_b_aux(dc, commands, 1);
}
int ft_rotate_b_untill_push_aux(t_data_container *dc)
{
	t_lsti *lst_b;
	int i;
	int j;
	
	i = 0;
	j = 0;
	lst_b = dc->b;
	while (!(dc->a->c > dc->b->c  && dc->a->c < dc->b->p->c ))
	{
		ft_rotate(&dc->b, 1, 0);
		i++;
	}
	dc->b = lst_b;
	while (!(dc->a->c > dc->b->c  && dc->a->c < dc->b->p->c))
	{
		ft_rrotate(&dc->b, 1, 0);
		j++;
	}
	dc->b = lst_b;
	if(i < j)
		return (0);
	else
		return (1);
}

void	ft_rotate_b_untill_push(t_data_container *dc, t_lsti **commands)
{
	if(ft_rotate_b_untill_push_aux(dc) == 0)
	{
		while (!(dc->a->c > dc->b->c  && dc->a->c < dc->b->p->c))
		{
			ft_rotate(&dc->b, 1, 0);
			ft_lstiadd_last(commands, ft_lstinew(6));
		}
	}
	else
	{
		while (!(dc->a->c > dc->b->c  && dc->a->c < dc->b->p->c))
		{
			ft_rrotate(&dc->b, 1, 0);
			ft_lstiadd_last(commands, ft_lstinew(9));
		}
	}
}
