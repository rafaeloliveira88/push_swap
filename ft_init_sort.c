/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:27:47 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/20 11:54:59 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_sort(t_data_container *dc)
{
	if (ft_lstisize(dc->a) == 4)
		ft_push(&dc->a, &dc->b, 1, 1);
	else if (ft_lstisize(dc->a) > 4)
	{
		ft_push(&dc->a, &dc->b, 1, 1);
		dc->min = dc->b->c;
		dc->max = dc->b->c;
		ft_push(&dc->a, &dc->b, 1, 1);
		if (dc->b->c < dc->min)
			dc->min = dc->b->c;
		else if(dc->b->c > dc->max)
			dc->max = dc->b->c;
	}
}

void	ft_sort(t_lsti **a)
{
	t_data_container	*dc;

	dc = malloc(sizeof(t_data_container));
	if (!dc)
		return ;
	dc->a = (*a);
	dc->b = NULL;
	dc->lists_commands = NULL;
	ft_init_sort(dc);
	if (ft_lstisize(dc->a) == 2 && ft_lstisize(dc->b) == 0)
		ft_sort_two(a);
	if (ft_lstisize(dc->a) == 3 && ft_lstisize(dc->b) == 0)
		ft_sort_three(a);
	if (ft_lstisize(dc->a) == 3 && ft_lstisize(dc->b) == 1)
		ft_sort_four(dc);
	if (ft_lstisize(dc->a) >= 3 && ft_lstisize(dc->b) == 2)
		ft_sort_turk(dc);
}
