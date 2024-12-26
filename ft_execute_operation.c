/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:42:27 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/26 18:14:25 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Execute the given operation on the stacks.
void	ft_execute_operation(int operation, t_data_container *dc)
{
	if (operation == 0)
		ft_swap(&dc->a, 0, 1);
	else if (operation == 1)
		ft_swap(&dc->b, 1, 1);
	else if (operation == 2)
		ft_swapall(&dc->a, &dc->b, 1);
	else if (operation == 3)
		ft_push(&dc->b, &dc->a, 0, 1);
	else if (operation == 4)
	{
		ft_push(&dc->a, &dc->b, 1, 1);
		ft_update_min_max_b(dc);
	}
	else if (operation == 5)
		ft_rotate(&dc->a, 0, 1);
	else if (operation == 6)
		ft_rotate(&dc->b, 1, 1);
	else if (operation == 7)
		ft_rotateall(&dc->a, &dc->b, 1);
	else if (operation == 8)
		ft_rrotate(&dc->a, 0, 1);
	else if (operation == 9)
		ft_rrotate(&dc->b, 1, 1);
	else if (operation == 10)
		ft_rrotateall(&dc->a, &dc->b, 1);
}

//Updates the maximum and minimum value of stack B
void	ft_update_min_max_b(t_data_container *dc)
{
	if (dc->b->c > dc->max_b)
		dc->max_b = dc->b->c;
	else if (dc->b->c < dc->min_b)
		dc->min_b = dc->b->c;
}
