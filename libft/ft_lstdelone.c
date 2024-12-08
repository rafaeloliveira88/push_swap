/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:26:05 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 12:13:08 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes as a parameter a node and frees the memory of
** the node’s content using the function ’del’ given
** as a parameter and free the node. The memory of
** ’next’ must not be freed.
** ------------------------------------------------------
** lst: The node to free.
** del: The address of the function used to delete
** the content.
** ------------------------------------------------------
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	(*del)(lst->content);
	free(lst);
}
