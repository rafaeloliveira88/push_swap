/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:31:29 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 12:11:10 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** It calculate the size that need to allocate
*/
static int	ft_get_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while ((n / 10) != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

/*
** It create the string that represent the number received as an argument
*/
static void	ft_itoa_aux(char *s, int signal, unsigned int nbr, int size)
{
	while ((size - 1) >= 0)
	{
		s[size - 1] = (nbr % 10) + '0';
		nbr /= 10;
		size--;
	}
	if (signal == -1)
		s[0] = '-';
}

/*
** Allocates memory and returns a string
** representing the integer received as an argument.
** Negative numbers must be handled.
** -------------------------------------------------
** n: the integer to convert.
** -------------------------------------------------
** The string representing the integer.
** NULL if the allocation fails.
*/
char	*ft_itoa(int n)
{
	char			*s;
	int				size;
	int				signal;
	unsigned int	nbr;

	size = ft_get_size(n);
	s = ft_calloc(size + 1, sizeof(char));
	if (s == NULL)
		return (0);
	signal = 1;
	if (n < 0)
	{
		signal = -1;
		nbr = -n;
	}
	else
		nbr = n;
	ft_itoa_aux(s, signal, nbr, size);
	return (s);
}
