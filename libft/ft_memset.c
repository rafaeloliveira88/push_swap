/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:08:33 by rafael            #+#    #+#             */
/*   Updated: 2024/11/01 16:43:28 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*array;
	size_t			i;

	i = 0;
	array = (unsigned char *)s;
	while (i < n)
	{
		array[i] = c;
		i++;
	}
	return ((void *)array);
}
