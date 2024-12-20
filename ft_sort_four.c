/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:24:32 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/19 11:24:49 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_four(t_data_container *dc)
{
	int	count;

	ft_sort_three(&dc->a);
	count = 0;
	while (dc->b->c > dc->a->c)
	{
		ft_rotate(&dc->a, 0, 1);
		count++;
		if (count == 3)
		{
			count = 0;
			break ;
		}
	}
	ft_push(&dc->b, &dc->a, 0, 1);
	while (count-- != 0)
		ft_rrotate(&dc->a, 0, 1);
	if (dc->a->c > dc->a->n->c)
		ft_rotate(&dc->a, 0, 1);
}