/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:03:53 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/19 12:04:03 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free(void *ptr)
{
	free(ptr);
}
/*
void ft_clean_temp_lists(t_data_container *dc)
{
	int size;
	int i;
	t_lsti *aux;
	size = ft_lstsize(dc->lists_commands);
	i = 0;
	while(i < size)
	{	
		aux = dc->lists_commands->c;
		ft_lsticlear(&aux);
		if(size > 1)
			dc->lists_commands = dc->lists_commands->n;
		i++;
	}
	free(dc->lists_commands);
}
*/