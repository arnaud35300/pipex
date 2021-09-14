/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:13:55 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:07:42 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Write len bytes of value c to the string b.
**
** @param	b	=> the string to modify.
** @param	c	=> the character to write.
** @param	len	=> the length of the writable area.
**
** @return	its first argument.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	char	*r;

	r = b;
	while (len)
	{
		*(char *)b = c;
		b++;
		len--;
	}
	return (r);
}
