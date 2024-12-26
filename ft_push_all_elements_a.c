/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_all_elements_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:02:34 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/26 17:58:19 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Function that pushes elements from stack A to stack B 
//when stack A has only 3 elements.
void	ft_push_all_elements(t_data_container *dc)
{
	ft_update_min_max_a(dc);
	while (ft_lstisize(dc->b) > 0)
	{
		if (dc->b->c > dc->max_a)
		{
			ft_rot_a_min_top(dc);
			ft_push(&dc->b, &dc->a, 0, 1);
		}
		else if (dc->b->c < dc->min_a)
		{
			ft_rot_a_min_top(dc);
			ft_push(&dc->b, &dc->a, 0, 1);
		}
		else
		{
			ft_rot_a_between_min_max(dc);
			ft_push(&dc->b, &dc->a, 0, 1);
		}
		ft_update_min_max_a(dc);
	}
}
