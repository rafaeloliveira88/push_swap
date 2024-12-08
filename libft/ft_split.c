/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:56:37 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/11/04 17:25:38 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** It calculate the number of string that needs to create the array of strings
*/
static int	ft_get_number_strings(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

/*
** It auxiliate the function ft_split to create the array of the strings
** The function copies each set of characters separated by the defined
** delimiter.
*/
static char	**ft_split_aux(char const *s, char c, char **array)
{
	int	i;
	int	j;
	int	element;

	element = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] != c && s[j])
				j++;
			array[element] = ft_calloc((j - i + 1), sizeof(char));
			if (array[element] == NULL)
				return (0);
			ft_strlcpy(array[element], (s + i), j - i + 1);
			i = j;
			element++;
		}
		else
			i++;
	}
	array[element] = 0;
	return (array);
}

/*
** Frees the memory allocated for an array of strings.
*/
static void	ft_free_memory(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	if (array != NULL)
		free(array);
}

/*
** "Divides a string of characters into an array of strings using a delimiter
** character.
*/
char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = (char **)ft_calloc(ft_get_number_strings(s, c) + 1, sizeof(char *));
	if (array == NULL)
		return (0);
	if (ft_split_aux(s, c, array) == NULL)
	{
		ft_free_memory(array);
		return (0);
	}
	return (array);
}
