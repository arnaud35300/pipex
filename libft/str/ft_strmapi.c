/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:17:20 by arguilla          #+#    #+#             */
/*   Updated: 2021/01/15 17:51:44 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applicate the function f for each character of the string s and create
** a new string with the new value.
**
** @param	s	=> the string to browse.
** @param	f	=> the function that will be call for each characters.
**
** @return	the new string.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r;
	int		i;

	if (!s)
		return (NULL);
	r = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!r || !s || !f)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		r[i] = (*f)(i, s[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
