/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:33:29 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 12:14:38 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a new node.
** The member variable ’content’ is initialized with
** the value of the parameter ’content’. The variable
** ’next’ is initialized to NULL.
-------------------------------------------------------------------
content: The content to create the node with.
-------------------------------------------------------------------
The new node
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = ft_calloc(1, sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = 0;
	return (new_node);
}
