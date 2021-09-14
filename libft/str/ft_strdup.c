/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 01:05:50 by arguilla          #+#    #+#             */
/*   Updated: 2021/01/08 13:08:07 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a copy of the string s.
**
** @param	s1	=> the string to copy.
**
** return	copy of s1.
*/

char	*ft_strdup(const char *s1)
{
	char	*s_copy;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	s_copy = malloc(sizeof(char) * (len + 1));
	if (!s_copy)
		return (NULL);
	while (i < len)
	{
		s_copy[i] = s1[i];
		i++;
	}
	s_copy[i] = '\0';
	return ((char *)(s_copy));
}
