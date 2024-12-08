/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:40:32 by rafael            #+#    #+#             */
/*   Updated: 2024/11/04 11:57:47 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** function check if a character is part of the ASCII set
** ASCII set includes characters in the range 0 to 127
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
