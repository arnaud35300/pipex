/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:18:42 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:11:51 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	assign(char *r, char const *s, size_t *i)
{
	while (*s)
	{
		r[*i] = *s;
		s++;
		(*i)++;
	}
}

/*
** Creation of a string resulting from the concatenation of two
** sub-strings.
**
** @param	s1	=> the first string.
** @param	s2	=> the second string.
**
** @return	the string resulting from the concatenation of s1 and s2.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	i;

	r = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!r)
		return (NULL);
	i = 0;
	assign(r, s1, &i);
	assign(r, s2, &i);
	r[i] = '\0';
	return (r);
}
