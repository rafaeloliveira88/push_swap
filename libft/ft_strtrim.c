/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:23:47 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/11/04 15:06:40 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswithin(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_getstartpostrim(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_iswithin(s1[i], set))
			i++;
		else
			return (i);
	}
	return (-1);
}

static int	ft_getendpostrim(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (ft_iswithin(s1[i], set))
			i--;
		else
			return (i);
	}
	return (-1);
}

/*
** Allocates (with malloc(3)) and returns a copy of
** ’s1’ with the characters specified in ’set’ removed
** from the beginning and the end of the string
** ----------------------------------------------------
** s1: The string to be trimmed.
** set: The reference set of characters to trim.
** ----------------------------------------------------
** The trimmed string.
** NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_string;
	int		start;
	int		end;

	start = ft_getstartpostrim(s1, set);
	end = ft_getendpostrim(s1, set);
	new_string = ft_substr(s1, start, end - start + 1);
	return (new_string);
}
