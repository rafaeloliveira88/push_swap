/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:54:54 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/26 18:03:46 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_choose_rot_a_aux(t_data_container *dc, int ind, int r, t_lsti **cmds)
{
	int	j;
	int	size;

	size = ft_lstisize(dc->a);
	j = 0;
	if (r == 0)
	{
		while (j < ind)
		{
			ft_rotate(&dc->a, 0, 0);
			ft_lstiadd_last(cmds, ft_lstinew(5));
			j++;
		}
	}
	else
	{
		while (ind < size)
		{
			ft_rrotate(&dc->a, 0, 0);
			ft_lstiadd_last(cmds, ft_lstinew(8));
			ind++;
		}
	}
}

//function that rotates for the case where the element is in 
//the middle of the stack
void	ft_choose_rot_a_aux_middle(t_data_container *dc, int ind, t_lsti **cmds)
{
	int	j;

	j = 0;
	while (j < ind)
	{
		ft_rotate(&dc->a, 0, 0);
		ft_lstiadd_last(cmds, ft_lstinew(11));
		j++;
	}
}

//function that will rotate stack A until the index is at the top
t_lsti	*ft_choose_rotate_a(t_data_container *dc, int index)
{
	t_lsti	*commands;
	int		size;
	int		i;

	commands = NULL;
	size = ft_lstisize(dc->a);
	i = 0;
	if ((size % 2) == 0 && (size / 2) == index)
	{
		ft_choose_rot_a_aux_middle(dc, index, &commands);
	}
	else
	{
		if (index <= (size / 2))
			ft_choose_rot_a_aux(dc, index, 0, &commands);
		else
			ft_choose_rot_a_aux(dc, index, 1, &commands);
	}
	return (commands);
}

//function that performs rotate A for the case where the number is 
//between the minimum and maximum value of stack A, so the value 
//of stack B must be greater than the last element of stack A and 
//less than the element at the top
int	ft_rot_a_between_min_max(t_data_container *dc)
{
	int		i;
	int		size;
	t_lsti	*a;

	a = dc->a;
	i = 0;
	size = ft_lstisize(dc->a);
	while (!(dc->b->c > dc->a->p->c && dc->b->c < dc->a->c))
	{
		ft_rotate(&dc->a, 0, 0);
		i++;
	}
	dc->a = a;
	while (!(dc->b->c > dc->a->p->c && dc->b->c < dc->a->c))
	{
		if ((size - i) > i)
			ft_rotate(&dc->a, 0, 1);
		else
			ft_rrotate(&dc->a, 0, 1);
	}
}

//Function that rotates A until the value at the top is the minimum 
//of stack A
void	ft_rot_a_min_top(t_data_container *dc)
{
	int		i;
	int		size;
	t_lsti	*a;

	a = dc->a;
	i = 0;
	size = ft_lstisize(dc->a);
	while (dc->a->c != dc->min_a)
	{
		ft_rotate(&dc->a, 0, 0);
		i++;
	}
	dc->a = a;
	while (dc->a->c != dc->min_a)
	{
		if ((size - i) > i)
			ft_rotate(&dc->a, 0, 1);
		else
			ft_rrotate(&dc->a, 0, 1);
	}
}
