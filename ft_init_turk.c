/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_turk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:30:49 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/20 11:55:46 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_turk(t_data_container *dc)
{
	while(ft_lstisize(dc->a) > 3)
	{
		ft_calculate_cheapest(dc);
		ft_execute_cheapest(dc);
	}
	ft_sort_three(&dc->a);
	ft_push_all_elements(dc);
	ft_rot_a_min_top(dc);
}
