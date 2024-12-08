/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:44:54 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 19:53:51 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memcpy function in C is used to copy a specific number of bytes from one
** memory location to another. It's commonly used when you want to copy raw
** memory, such as arrays, structures, or parts of a string. The function is
** defined in the <string.h> library.
** ----------------------------------------------------------------------------
** dest: Pointer to the destination memory location where data will be copied.
** src: Pointer to the source memory location from where data will be copied.
** n: Number of bytes to copy.
** ----------------------------------------------------------------------------
** memcpy returns a pointer to the destination (dest).
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_c;
	const unsigned char	*src_c;

	if (!dest && !src)
		return (NULL);
	src_c = (const unsigned char *)src;
	dest_c = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	return (dest);
}
