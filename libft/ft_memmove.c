/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:45:44 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 13:35:45 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memmove function in C is used to copy a specified number of bytes
** from one memory location to another.
** The key feature of memmove is that it handles overlapping
** memory regions correctly, making it more flexible than memcpy for certain
** situations.
** ----------------------------------------------------------------------------
** dest: A pointer to the destination memory area where the bytes will be
** copied.
** src: A pointer to the source memory area from which the bytes will be
** copied.
** num: The number of bytes to copy from the source to the destination.
** ----------------------------------------------------------------------------
** The function returns a pointer to the destination (dest).
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_c;
	const unsigned char	*src_c;

	if (!dest && !src)
		return (NULL);
	dest_c = (unsigned char *)dest;
	src_c = (unsigned const char *)src;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else
		while (n-- > 0)
			dest_c[n] = src_c[n];
	return (dest);
}
