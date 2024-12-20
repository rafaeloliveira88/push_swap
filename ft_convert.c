/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:17:34 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/20 11:47:29 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_atoi_check_integer(const char *str, int *bigger)
{
	int	i;
	long	number;
	int	signal;

	number = 0;
	ft_get_position(&signal, &i, str);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
		if(signal > 0 && number*signal > INT_MAX)
		{
			*bigger = 1;
			break;
		}
		else if(signal < 0 && number*signal < INT_MIN)
		{
			*bigger = 1;
			break;
		}
	}
	return (signal * (int)number);
}

int	ft_atoi(const char *str)
{
	int	i;
	long	number;
	int	signal;

	number = 0;
	ft_get_position(&signal, &i, str);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (signal * (int)number);
}

int ft_isnumber(char *str)
{
	if(*str == '-')
		str++;
	while(*str >= '0' && *str <= '9')
		str++;
	if(!(*str))
		return (1);
	else
		return (0);
}
