/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:41:04 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 12:01:44 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if a character is printable
** The printable character are in range 32 to 126
** the character space is considered printable
*/
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
