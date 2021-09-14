/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 00:43:13 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:11:19 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** locates the first occurence of c in string s.
**
** @param	s	=> the string to browse.
** @param	c	=> the character to find.
**
** @return	pointer to the first occurence of c in string s, NULL if c is not
** in str.
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)(s));
		s++;
	}
	if (c == '\0')
		return ((char *)(s));
	return (NULL);
}
