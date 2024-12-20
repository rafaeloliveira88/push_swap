/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:00:39 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/20 11:31:10 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_update_min_max_a(t_data_container *dc)
{
	int size;
	t_lsti *a;

	dc->min = dc->a->c;
	dc->max = dc->a->c;
	size = ft_lstisize(dc->a);
	a = dc->a;
	while(size-- != 0)
	{
		if(dc->a->c > dc->max)
			dc->max = dc->a->c;
		else if(dc->a->c < dc->min)
			dc->min = dc->a->c;
		if(dc->a->n)
			dc->a = dc->a->n;
	}
	dc->a = a;
}
