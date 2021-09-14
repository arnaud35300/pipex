/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:00:22 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:14:04 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Same as ft_libft.hr but the search start at the end of the string s.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*last_match;

	last_match = NULL;
	while (*s)
	{
		if (*s == c)
			last_match = ((char *)(s));
		s++;
	}
	if (c == '\0')
		last_match = ((char *)(s));
	return (last_match);
}
