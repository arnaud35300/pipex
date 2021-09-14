/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:50:12 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:09:41 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** locates the first occurence of c in string s
**
** @param	s	=> the string to browse.
** @param	c	=> the character to find.
**
** @return	pointer to the first occurence of c in string s, NULL if c is not
** in str.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	charset;
	unsigned char	*compare;
	size_t			i;

	i = 0;
	charset = (unsigned char)c;
	compare = (unsigned char *)s;
	while (i < n)
	{
		if (charset == compare[i])
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
