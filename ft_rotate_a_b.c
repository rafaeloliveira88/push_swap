/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:00:39 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/26 17:59:08 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_update_min_max_a(t_data_container *dc)
{
	int		size;
	t_lsti	*a;

	dc->min_a = dc->a->c;
	dc->max_a = dc->a->c;
	size = ft_lstisize(dc->a);
	a = dc->a;
	while (size-- != 0)
	{
		if (dc->a->c > dc->max_a)
			dc->max_a = dc->a->c;
		else if (dc->a->c < dc->min_a)
			dc->min_a = dc->a->c;
		if (dc->a->n)
			dc->a = dc->a->n;
	}
	dc->a = a;
}
