/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheapest_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:41:35 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/26 18:15:05 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Check which list is the smallest; the smallest list indicates that 
//it has the fewest operations to sort the next element.
int	ft_get_cheapest(t_data_container *dc)
{
	int		size;
	int		cheapest;
	int		size_cheapest;
	t_lst	*head;
	int		i;

	i = 0;
	head = dc->lists_commands;
	size = ft_lstsize(dc->lists_commands);
	cheapest = -1;
	while (size-- != 0)
	{
		if (cheapest == -1
			|| size_cheapest > ft_lstisize(dc->lists_commands->c))
		{
			size_cheapest = ft_lstisize(dc->lists_commands->c);
			cheapest = i;
		}
		dc->lists_commands = dc->lists_commands->n;
		i++;
	}
	dc->lists_commands = head;
	return (cheapest);
}

//This function executes the operations of the "cheapest list".
void	ft_execute_cheapest(t_data_container *dc)
{
	int		i;
	t_lst	*current;
	t_lsti	*operations;
	int		cheapest;

	i = 0;
	current = dc->lists_commands;
	cheapest = ft_get_cheapest(dc);
	while (i < cheapest)
	{
		current = current->n;
		i++;
	}
	operations = current->c;
	i = ft_lstisize(operations);
	while (i-- != 0)
	{
		ft_execute_operation(operations->c, dc);
		operations = operations->n;
	}
	ft_lstclear(&dc->lists_commands, free);
}

//This is the function that assists the "calculate cheapest" function
//This function determines the necessary operations to place 
//the element at position X from stack A into stack B
t_lsti	*ft_cheap_aux(t_data_container *dc, int index)
{
	t_lsti	*commands;
	t_lsti	*temp_commands;

	commands = NULL;
	if (index != 0)
		temp_commands = ft_choose_rotate_a(dc, index);
	if (dc->a->c < dc->min_b || dc->a->c > dc->max_b)
		ft_rotate_b_untill_top_max(dc, &commands);
	else if (dc->a->c > dc->min_b && dc->a->c < dc->max_b)
		ft_rotate_b_untill_push(dc, &commands);
	if (index > 0)
	{
		ft_check_match_operations(&temp_commands, &commands);
		ft_lsticlear(&temp_commands);
	}
	ft_lstiadd_last(&commands, ft_lstinew(4));
	return (commands);
}

//This function creates a list of sorting operations for each element of 
//stack A
void	ft_calculate_cheapest(t_data_container *dc)
{
	int		size;
	int		size_temp;
	t_lsti	*a;
	t_lsti	*b;
	t_lsti	*temp;

	a = dc->a;
	b = dc->b;
	dc->lists_commands = NULL;
	size = ft_lstisize(dc->a);
	size_temp = size;
	while (size_temp-- != 0)
	{
		temp = ft_cheap_aux(dc, size - (size_temp + 1));
		ft_lstadd_last(&dc->lists_commands, ft_lstnew(temp));
		dc->a = a;
		dc->b = b;
	}
}
