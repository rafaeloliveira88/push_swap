/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheapest_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:41:35 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/20 11:35:47 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_get_cheapest(t_data_container *dc)
{
	int size;
	int cheapest;
	int cheapest_aux;
	t_lst *head;
	int i;
	
	i = 0;
	head = dc->lists_commands;
	size = ft_lstsize(dc->lists_commands);
	cheapest = -1;
	while(size-- != 0)
	{
		if(cheapest == -1 || cheapest_aux > ft_lstisize(dc->lists_commands->c))
		{
			cheapest_aux = ft_lstisize(dc->lists_commands->c);
			cheapest = i;
		}
		dc->lists_commands = dc->lists_commands->n;
		i++;	
	}
	dc->lists_commands = head;
	return cheapest;
}

void ft_execute_cheapest(t_data_container *dc)
{
	int i;
	t_lst	*current;
	t_lsti	*operations;
	int cheapest;

	i = 0;
	current = dc->lists_commands;
	cheapest = ft_get_cheapest(dc);
	while(i < cheapest)
	{
		current = current->n;
		i++;
	}
	operations = current->c;
	i = ft_lstisize(operations);
	while(i-- != 0)
	{
		ft_execute_operation(operations->c, dc);
		operations = operations->n;
	}
	ft_lstclear(&dc->lists_commands, free);
}

t_lsti	*ft_cheap_aux(t_data_container *dc, int index)
{
	t_lsti	*commands;
	t_lsti *temp_commands;

	commands = NULL;
	if(index != 0)
		temp_commands = ft_choose_rotate_a(dc, index);
	if (dc->a->c < dc->min || dc->a->c > dc->max)
		ft_rotate_b_untill_top_max(dc, &commands);
	else if (dc->a->c > dc->min && dc->a->c < dc->max)
		ft_rotate_b_untill_push(dc, &commands);
	if(index > 0)
		ft_check_match_operations(&temp_commands, &commands);
	ft_lstiadd_last(&commands, ft_lstinew(4));
	return (commands);
}

void ft_calculate_cheapest(t_data_container *dc)
{
	t_lst	*list_of_lists;
	int		size;
	int size_temp;
	t_lsti *a;
	t_lsti *b;
	
	a = dc->a;
	b = dc->b;
	list_of_lists = NULL;
	size = ft_lstisize(dc->a);
	
	size_temp = size;
	
	while (size_temp-- != 0)
	{
		t_lsti *temp = ft_cheap_aux(dc, size-(size_temp+1));
		
		ft_lstadd_last(&list_of_lists, ft_lstnew(temp));
		dc->a = a;
		dc->b = b;
	}
	dc->lists_commands = list_of_lists;
}
