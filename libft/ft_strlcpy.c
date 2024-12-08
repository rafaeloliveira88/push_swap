/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:47:36 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 13:11:45 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** function is a safer alternative for copying strings in C,
** particularly useful for avoiding buffer overflow issues by
** ensuring the destination buffer's size is respected.
** The main purpose of strlcpy is to always null-terminate the copied string.
** --------------------------------------------------------------------------
** dst: The destination buffer where the string will be copied.
** src: The source string to be copied into dst.
** dstsize: The size of the destination buffer,
** including space for the null terminator (\0).
** Return value:
** strlcpy returns the total length of the string it attempted to copy from src.
** This means if src is larger than dstsize, the return value will be greater
** than dstsize - 1.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (dest == NULL || size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
