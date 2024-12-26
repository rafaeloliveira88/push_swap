/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:56:59 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/20 14:44:40 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_sorted(t_lsti *lst)
{
	int size;

	size = ft_lstisize(lst);
	while(size-- != 0 && lst->n->c > lst->c)
		lst = lst->n;
	if(size == 0)
		return (1);
	return (0);
}