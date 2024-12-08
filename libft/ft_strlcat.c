/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:48:50 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 13:08:28 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strlcat function is designed to safely concatenate two strings.
** It helps prevent buffer overflows, which can occur when the
** destination buffer is not large enough to hold the concatenated
** result. The function ensures that the destination string is properly
** null-terminated.
** ---------------------------------------------------------------------
** dst: A pointer to the destination string where the src string will
** be appended.
** src: A pointer to the source string that will be appended to dst.
** size: The total size of the destination buffer (dst), including
** space for the null terminator (\0).
** The return value of strlcat is the total length of the string that
** would have been created if there were enough space in dst to hold the
** entire concatenated result. This value is calculated as:
** length = length of src + length of dst
** If the size parameter is 0, return length of src
** if size <= length of dest then return len of src + size
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	if (size <= (len_dest))
		return (len_src + size);
	while (src[i] && i < (size - len_dest - 1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
