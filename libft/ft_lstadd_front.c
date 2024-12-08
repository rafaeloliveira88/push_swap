/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:49:14 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 12:12:14 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds the node ’new’ at the beginning of the list.
** ---------------------------------------------------------------
** lst: The address of a pointer to the first link of
** a list.
** new: The address of a pointer to the node to be
** added to the list.
** ---------------------------------------------------------------
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
