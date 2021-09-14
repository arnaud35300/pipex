/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:30:42 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:05:26 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count the number of characters in a string.
**
** @param	s	=> the string whose length we want to know.
**
** return	the length of the string s.
*/

size_t	ft_strlen_g(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

/*
** locates the first occurence of '\n' in string s.
**
** @param	s	=> the string to browse.
**
** @return	pointer to the first occurence of '\n' in string s, NULL if '\n'
** is not in str.
*/

int	check_line(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

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

char	*ft_substr_g(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	i = start;
	if (!s)
		return (NULL);
	while (s[i] && i < len)
		i++;
	r = malloc(sizeof(char) * (i + 1));
	if (!r)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		r[i++] = s[start++];
	if (start > ft_strlen_g(s))
		r[0] = '\0';
	r[i] = '\0';
	return (r);
}

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

char	*ft_strjoin_g(char const *s1, char const *s2)
{
	char	*r;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	r = malloc(sizeof(char) * (ft_strlen_g(s1) + ft_strlen_g(s2) + 1));
	if (!r)
		return (NULL);
	i = 0;
	assign(r, s1, &i);
	assign(r, s2, &i);
	r[i] = '\0';
	return (r);
}
