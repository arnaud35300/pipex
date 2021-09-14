/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 09:15:30 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:10:40 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char charset)
{
	return (c == charset || c == '\0');
}

static int	get_tab_len(char const *s, char c)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (s && !is_charset(s[0], c))
		count++;
	while (s && s[0] && s[i])
	{
		if (is_charset(s[i - 1], c) && !is_charset(s[i], c))
			count++;
		i++;
	}
	return (count);
}

static char	*assign_char(char *current_s, char const **s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (is_charset(*(*s), c))
		(*s)++;
	while (!is_charset(*(*s + len), c))
		len++;
	current_s = malloc(sizeof(char) * len + 1);
	if (!current_s)
		return (current_s);
	while (!is_charset(*(*s + i), c))
	{
		current_s[i] = *(*s + i);
		i++;
	}
	current_s[i] = '\0';
	(*s) += len;
	return (current_s);
}

static char	**exit_and_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

/*
** Split a string when c is in the string s, and store split value
** in a array of strings.
**
** @param	s	=> the string to split.
** @param	c	=> the delimiter.
**
** @return	array of multiples part of the string s, NULL if malloc fails.
*/

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		len;
	int		i;

	len = get_tab_len(s, c);
	tab = malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (s && i < len)
	{
		tab[i] = assign_char(tab[i], &s, c);
		if (!tab[i])
			return (exit_and_free(tab));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
