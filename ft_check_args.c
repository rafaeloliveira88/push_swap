/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:09:27 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/20 11:48:14 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_args(int size, char **args)
{
	int	i;
	int	bigger_int;

	i = 1;
	bigger_int = 0;
	while (i < size)
	{
		if (!ft_isnumber(args[i]))
			return (0);
		else
			i++;
	}
	i = 1;
	while (i < size)
	{
		ft_atoi_check_integer(args[i++], &bigger_int);
		if (bigger_int)
			return (0);
	}
	return (1);
}
