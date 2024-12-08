/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:49:41 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 12:56:00 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** It locates the first occurrence of a character in a string.
*/
char	*ft_strchr(const char *s, int c)
{
	int	i;

	if ((char)c == 0)
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i])
		return ((void *)&s[i]);
	return (0);
}
