/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:54:39 by arguilla          #+#    #+#             */
/*   Updated: 2021/01/29 09:32:54 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a new string starting at index start in the string s and which ends
** when the new string length is less or equal to len.
**
** @param	s		=> the string to browse.
** @param	start	=> the index which represents the beginning
** of the new string.
** @param	len		=> the max length of the new string.
**
** @return the new string.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	while (i < len && start < ft_strlen(s))
	{
		r[i] = s[start + i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
