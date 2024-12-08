/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:32:55 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 13:14:49 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to each character of the
** string s, passing its index as the first argument
** and the character itself as the second. A new
** string is created malloc to collect the
** results from the successive applications of f.
** --------------------------------------------------
** s: The string on which to iterate.
** f: The function to apply to each character.
** --------------------------------------------------
** The string created from the successive applications
** of ’f’.
** Returns NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	int		i;

	if (!s || !(*f))
		return (NULL);
	s2 = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (s2 == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		s2[i] = (*f)(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
