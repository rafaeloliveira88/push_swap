/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:03:53 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/20 13:41:40 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(void *ptr)
{
	free(ptr);
}

void	ft_free_all(t_data_container *dc)
{
	ft_lsticlear(&dc->a);
	ft_lsticlear(&dc->b);
	free(dc);
}
