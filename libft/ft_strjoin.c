/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:56:25 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/11/04 13:06:18 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
------------------------------------------------
s1: The prefix string.
s2: The suffix string
------------------------------------------------
The new string.
NULL if the allocation fails
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;

	if (!s1 || !s2)
		return (NULL);
	new_string = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (new_string == NULL)
		return (0);
	ft_strlcpy(new_string, s1, ft_strlen(s1) + 1);
	ft_strlcat(new_string, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (new_string);
}
