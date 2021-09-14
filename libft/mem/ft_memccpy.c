/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 02:04:11 by arguilla          #+#    #+#             */
/*   Updated: 2021/01/08 10:44:55 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies bytes from string src to string desti while c is not
** in the src string..
**
** @param	dest	=> the string destination.
** @param	src		=> the string source.
** @param	c		=> the character that not must be in str.
** @param	n		=> the number of bytes to be copied in dest.
**
** @return	NULL, pointer to the positon of match c in str
** if c is in the str string.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n)
	{
		*(char *)dest = *(char *)src;
		dest++;
		if (c == *(char *)src)
			return (dest);
		src++;
		n--;
	}
	return (NULL);
}
