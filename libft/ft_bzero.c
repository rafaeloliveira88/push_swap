/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:05:03 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 11:52:55 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_bzero function places the NULL terminator in the first n bytes of
** the variable s.
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
