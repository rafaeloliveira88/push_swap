/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:09:27 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/12 19:06:48 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_args(int size, char **args)
{
	int	i;
    int bigger_int;
    
	i = 1;
    bigger_int = 0;
	while (i < size)
	{
        if(!ft_isnumber(args[i]))
            return (0);
        else
            i++;
	}
    if(i == size)
    {
        i = 1;
        while(i < size)
        {
            ft_atoic(args[i++],&bigger_int);
            if(bigger_int)
                return (0);
        }
    }
    else
    {
        return (0);
    }
	return (1);
}
