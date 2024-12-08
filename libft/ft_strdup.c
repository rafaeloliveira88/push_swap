/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:43:02 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 12:58:58 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The	strdup(void)  function returns a pointer to a new string which is a
** duplicate of the string s.  Memory for the new string is obtained with
** malloc, and can be freed with free.
** On  success,  the  strdup() function returns a pointer to the duplicated
** string.
** It returns NULL if insufficient memory was available, with errno set to
**  indicate the cause of  the  error.
*/
char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	dup = ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (dup == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}
