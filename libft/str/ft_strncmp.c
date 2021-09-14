/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:37:49 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:13:30 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compares the string s1 with the string s1 up to n characters.
**
** @param	s1	=> the string that wll be compared with s2.
** @param	s2	=> the string that wll be compared with s1.
**
** @return	0 if the two strings are identical, otherwise returns the
** difference between the first two differing bytes.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((i < n - 1) && (s1[i] == s2[i]) && s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
