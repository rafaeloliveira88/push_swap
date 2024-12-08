/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:13:19 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/11/04 15:04:51 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a substring
** from the string ’s’.
** The substring begins at index ’start’ and is of
** maximum size ’len’.
** ------------------------------------------------
** s: The string from which to create the substring.
** start: The start index of the substring in the
** string ’s’.
** ------------------------------------------------
** len: The maximum length of the substring.
** The substring.
** NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;

	if (s == NULL || (start > (unsigned int)ft_strlen(s)))
	{
		new_string = ft_calloc(1, sizeof(char));
		return (new_string);
	}
	if (len > ft_strlen(s) - start)
		new_string = ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	else
		new_string = ft_calloc(len + 1, sizeof(char));
	if (new_string == NULL)
		return (0);
	if (len > ft_strlen(s) - start)
		ft_strlcpy(new_string, s + start, ft_strlen(s) - start + 1);
	else
		ft_strlcpy(new_string, s + start, len + 1);
	return (new_string);
}
