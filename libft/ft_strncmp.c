/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:53:07 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 13:44:50 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strncmp function in C is used to compare a specific number of characters
** between two strings.
** str1: The first string to compare.
** str2: The second string to compare.
** n: The maximum number of characters to compare.
** strncmp returns an integer based on the comparison:
** 0 if the first n characters of both strings are equal.
** Negative value if str1 is lexicographically less than str2 in the first n
** characters.
** Positive value if str1 is lexicographically greater than str2 in the first n
** characters.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < n - 1)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
