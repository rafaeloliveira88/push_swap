/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:45:22 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 12:16:57 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memchr function in C is used to locate the first occurrence of a
** specific character in a block of memory.
** -------------------------------------------------------------------------
** ptr: A pointer to the block of memory where the search will be performed.
** value: The character to search for, passed as an integer. This value is
** treated as an unsigned char during the comparison.
** num: The number of bytes to examine in the block of memory.
** -------------------------------------------------------------------------
** The function returns a pointer to the first occurrence of the character
** value in the block of memory pointed to by ptr.
** If the character is not found, the function returns NULL.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*src;

	src = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return ((void *)&src[i]);
		i++;
	}
	return (0);
}
