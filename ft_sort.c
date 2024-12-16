/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:15:59 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/13 22:47:14 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_sort(t_data_container *x)
{
	if (ft_lstisize(x->a) == 4)
		ft_push(&x->a, &x->b, 1, 1);
	else if (ft_lstisize(x->a) > 4)
	{
		ft_push(&x->a, &x->b, 1, 1);
		x->min = x->b->c;
		x->max = x->b->c;
		ft_push(&x->a, &x->b, 1, 1);
		if (x->b->c > x->min)
			x->max = x->b->c;
		else
			x->min = x->b->c;
	}
}

void	ft_sort_three(t_lsti **s)
{
	if ((*s)->c > (*s)->n->c && (*s)->c > (*s)->p->c && (*s)->n->c > (*s)->p->c)
	{
		ft_rotate(s, 0, 1);
		ft_swap(s, 0, 1);
	}
	if ((*s)->c < (*s)->n->c && (*s)->c > (*s)->p->c && (*s)->n->c > (*s)->p->c)
    {
		ft_rrotate(s, 0, 1);
    }
	if ((*s)->c > (*s)->n->c && (*s)->c > (*s)->p->c && (*s)->n->c < (*s)->p->c)
		ft_rotate(s, 0, 1);
	if ((*s)->c > (*s)->n->c && (*s)->c < (*s)->p->c && (*s)->n->c < (*s)->p->c)
		ft_swap(s, 0, 1);
	if ((*s)->c < (*s)->n->c && (*s)->c < (*s)->p->c && (*s)->n->c > (*s)->p->c)
	{
		ft_rrotate(s, 0, 1);
		ft_swap(s, 0, 1);
	}
}

void	ft_sort_two(t_lsti **a)
{
	if ((*a)->c > ((*a)->n->c))
		ft_swap(a, 0, 1);
}

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

void	ft_rotate_b_untill_top_max(t_data_container *x, t_lsti **commands)
{
	while ((x->b)->c != x->max)
	{
		ft_rotate(&x->b, 1, 0);
		ft_lstiadd_last(commands, ft_lstinew(6));
	}
}

void	ft_rotate_b_untill_push(t_data_container *x, t_lsti **commands)
{
	while (!(x->b->p->c > x->a->c && x->b->c < x->a->c))
	{
		ft_rotate(&x->b, 1, 0);
		ft_lstiadd_last(commands, ft_lstinew(6));
	}
}

void ft_choose_rot_a_aux(t_data_container *x, int ind, int r, t_lsti **cmds)
{
	int j;
	int size;

	size = ft_lstisize(x->a);
	j = 0;
	if(r == 0) //rotate
	{
		while(j < ind)
		{
			ft_rotate(&x->a, 0, 0);
			ft_lstiadd_last(cmds, ft_lstinew(5));
			j++;
		}
	}
	else //reverse rotate
	{
		while(ind < size)
		{
			ft_rrotate(&x->a, 0, 0);
			ft_lstiadd_last(cmds, ft_lstinew(8));
			ind++;
		}
	}
}

t_lsti	*ft_choose_rotate_a(t_data_container *x, int index)
{
	t_lsti	*commands;
	int size;
	int i;

	commands = NULL;
	size = ft_lstisize(x->a);
	i = 0;
	
	if((size%2) == 0 && (size / 2) == index ) //the number is in the middle of stack 
	{
		while(i++ < (size / 2))
			ft_lstiadd_front(&commands, ft_lstinew(11));
	}
	else
	{
		if(index <= (size/2))// first middle part
			ft_choose_rot_a_aux(x, index, 0, &commands);
		else //after middle part
				ft_choose_rot_a_aux(x, index, 1, &commands);
	}

	return (commands);
}

void	ft_insert_cmd_list(t_lsti **temp, t_lsti **cmd, int i)
{
	int size;
	
	size = ft_lstisize(*temp);

	while(i < size)
	{
		if((*temp)->c == 5)
			ft_lstiadd_front(cmd, ft_lstinew(5));
		else
			ft_lstiadd_front(cmd, ft_lstinew(8));
		*temp = (*temp)->n;
		i++;
	}
	//ft_lsticlear(temp);
}

void ft_check_match_operations(t_lsti **temp, t_lsti **cmd)
{
	t_lsti	*first;
	int	i;
	first = (*cmd);
	i = 0;

	while(i < ft_lstisize(*temp) && i < ft_lstisize(*cmd))
	{
		if(((*temp)->c == 5 || (*temp)->c == 11) && (*cmd)->c == 6)
			(*cmd)->c = 7;
		else if(((*temp)->c == 8 || (*temp)->c == 11) && (*cmd)->c == 9)
			(*cmd)->c = 10;
		else
			break;
		if((*temp)->n)
			*temp = (*temp)->n;
		if((*cmd)->n)
			*cmd = (*cmd)->n;
		i++;
	}
	if(i != ft_lstisize(*temp))
		ft_insert_cmd_list(temp, cmd, i);
	*cmd = first;
}

t_lsti	*ft_cheap_aux(t_data_container *x, int index)
{
	t_lsti	*commands;
	t_lsti *temp_commands;

	commands = NULL;
	if(index != 0)
		temp_commands = ft_choose_rotate_a(x, index);
	if (x->a->c < x->min || x->a->c > x->max)
		ft_rotate_b_untill_top_max(x, &commands);
	else if (x->a->c > x->min && x->a->c < x->max)
		ft_rotate_b_untill_push(x, &commands);
	if(index > 0)
		ft_check_match_operations(&temp_commands, &commands);
	ft_lstiadd_last(&commands, ft_lstinew(4));
	return (commands);
}

void ft_calculate_cheapest(t_data_container *x)
{
	t_lst	*list_of_lists;
	int		size;
	int size_temp;
	t_lsti *a;
	t_lsti *b;
	
	a = x->a;
	b = x->b;
	list_of_lists = NULL;
	size = ft_lstisize(x->a);
	
	size_temp = size;
	
	while (size_temp-- != 0)
	{
		t_lsti *temp = ft_cheap_aux(x, size-size_temp-1);
		
		ft_lstadd_last(&list_of_lists, ft_lstnew(temp));
		x->a = a;
		x->b = b;
	}
	x->lists_commands = list_of_lists;
}

void	ft_sort_turk(t_data_container *x)
{
	ft_calculate_cheapest(x);
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
	
	int i = 0;
	int size = ft_lstsize(dc->lists_commands);
	while(i < size)
	{
		ft_print_stack(dc->lists_commands->c);
		dc->lists_commands = dc->lists_commands->n;
		i++;
	}
	
}
