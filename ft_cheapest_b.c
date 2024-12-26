/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheapest_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:44:25 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/26 15:58:10 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Checks for compatibility between rotates
//if there is a rotate a and rotate b, it replaces the operation with a rotateall
//the same applies for reverse rotate
void	ft_check_match_operations(t_lsti **temp, t_lsti **cmd)
{
	int	i;

	i = 0;
	while (i < ft_lstisize(*temp) && i < ft_lstisize(*cmd))
	{
		if (((*temp)->c == 5 || (*temp)->c == 11) && (*cmd)->c == 6)
			(*cmd)->c = 7;
		else if (((*temp)->c == 8 || (*temp)->c == 11) && (*cmd)->c == 9)
			(*cmd)->c = 10;
		else
			break ;
		if ((*temp)->n)
			*temp = (*temp)->n;
		if ((*cmd)->n)
			*cmd = (*cmd)->n;
		i++;
	}
	if (i != ft_lstisize(*temp))
		ft_insert_cmd_list(temp, cmd, i);
}

//Combine all the operations into a single list.
void	ft_insert_cmd_list(t_lsti **temp, t_lsti **cmd, int i)
{
	int		size;
	t_lsti	*head_temp;

	head_temp = *temp;
	size = ft_lstisize(*temp);
	while (i < size)
	{
		if ((*temp)->c == 5)
			ft_lstiadd_front(cmd, ft_lstinew(5));
		else
			ft_lstiadd_front(cmd, ft_lstinew(8));
		if ((*temp)->n)
			*temp = (*temp)->n;
		i++;
	}
	*temp = head_temp;
}
