/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:47:28 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:15:03 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
** Create a copy of the string s1 without the set characters at the beginning
** and at the end of the string s1.
**
** @param	s1	=> the string to trim.
** @param	set	=> the character to remove.
**
** @return	new string without the set character at the beginning and
** at the end.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*r;
	size_t		i;
	size_t		len;

	i = 0;
	while (is_set(*s1, set) && *s1)
		s1++;
	len = ft_strlen(s1);
	if (!len)
		return (ft_strdup(""));
	while (is_set(s1[len - 1], set) && len)
	{
		i++;
		len--;
	}
	len = ft_strlen(s1) - i;
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	i = -1;
	while (++i < len)
		r[i] = s1[i];
	r[i] = '\0';
	return (r);
}
