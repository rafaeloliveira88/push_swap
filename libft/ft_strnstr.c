/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:52:25 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 19:41:35 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Strnstr is used to locate a substring within a specified
** portion of a string. It's a safer variant of the strstr function,
** allowing you to limit the search to a given number of characters from
** the start of the main string.
** s1: The main string to search within
** s2: The substring to search for.
** n: The maximum number of characters in s1 to consider in the search.
** Returns a pointer to the beginning of the first occurrence of needle in s1,
** if found within the first len characters.
** Returns NULL if needle is not found within the specified portion of s1.
*/
char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (s2 != NULL && s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] && (n - i) >= ft_strlen(s2))
	{
		if (ft_strncmp(s1 + i, s2, ft_strlen(s2)) == 0)
			return ((char *)(s1 + i));
		i++;
	}
	return (0);
}
