/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:44:05 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 11:53:16 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The	calloc(void) function allocates memory for an array of nmemb elements of
** size bytes each and returns  a pointer to the allocated memory.  The memory
** is set to zero.
** If nmemb or size is 0, then calloc() returns unique pointer value
** that can later  be  successfully  passed  to	free(void). If the
** multiplication of nmemb and size would result in integer overflow, then
** calloc() returns a NULL pointer. By contrast, an integer overflow would not
** be detected in the following call to	malloc(void), with the result that an
** incorrectly sized block of memory would be allocated:
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (((nmemb * size) / nmemb) != size)
		return (0);
	mem = (void *)malloc(nmemb * size);
	if (mem == NULL)
		return (0);
	ft_bzero(mem, size * nmemb);
	return (mem);
}
