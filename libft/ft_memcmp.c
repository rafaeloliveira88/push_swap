/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:57:07 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 12:23:23 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The	memcmp(void)  function compares the first n bytes (each interpreted as
** unsigned char) of the memory areas s1 and s2.
** -----------------------------------------------------------------------
** The	memcmp(void) function returns  an  integer  less  than,  equal  to,  or
** greater than zero if the first n bytes of s1 is found, respectively, to
** be less than, to match, or be greater than the first n bytes of s2.
** ----------------------------------------------------------------------------
** For  a  nonzero return value, the sign is determined by the sign of the
** difference between the first pair of  bytes  (interpreted  as  unsigned
** char) that differ in s1 and s2.
** ----------------------------------------------------------------------------
** If n is zero, the return value is zero.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*s1_c;
	unsigned const char	*s2_c;

	if (n == 0)
		return (0);
	i = 0;
	s1_c = (unsigned const char *)s1;
	s2_c = (unsigned const char *)s2;
	while (i < n - 1)
	{
		if ((s1_c[i]) != (s2_c[i]))
			return ((s1_c[i]) - (s2_c[i]));
		i++;
	}
	return ((s1_c[i]) - (s2_c[i]));
}
