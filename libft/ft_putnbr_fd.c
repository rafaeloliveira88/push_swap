/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:04:23 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 16:20:20 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the integer ’n’ to the given file
** descriptor.
** --------------------------------------------------------------------------
** n: The integer to output.
** fd: The file descriptor on which to write.
*/
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	int				c;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr >= 10)
		ft_putnbr_fd((nbr / 10), fd);
	c = (nbr % 10) + '0';
	ft_putchar_fd(c, fd);
}
