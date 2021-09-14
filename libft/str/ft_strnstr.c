/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:03:04 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:13:49 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Find the first occurence of the string needle in the string haystack,
** with len as the max chain browsing size.
**
** @param	haystack	=> the string to browse.
** @param	needle		=> the string to find in the string haystack.
** @param	len			=> the max-length can will be parcourate in the string
** haystack.
**
** @return	pointer to the first occurence of needle in haystack, NULL if
** needle is not in the string haystack.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0' && needle[j] != '\0')
	{
		if (haystack[i] == needle[j])
			j++;
		else if (j > 0)
		{
			j = 0;
			i--;
		}
		i++;
	}
	if (j == ft_strlen(needle))
		return ((char *)&haystack[i - j]);
	return (NULL);
}
