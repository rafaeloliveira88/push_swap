/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:50:22 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/11/04 11:52:41 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function does several things: it writes 1 or -1 to the signal parameter
** if the number is negative, and it writes the index in the string where the
** number starts to the position parameter.
*/
static void	ft_get_position(int *signal, int *position, const char *s)
{
	int	i;

	*signal = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\f' || s[i] == '\n' || s[i] == '\r'
			|| s[i] == '\t' || s[i] == '\v')
			i++;
		else
			break ;
	}
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			*signal *= -1;
		i++;
	}
	*position = i;
}

/*
** Convert a string to an integer.
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	signal;

	number = 0;
	ft_get_position(&signal, &i, str);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (signal * number);
}
