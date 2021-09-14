/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:10:25 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:12:21 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy and concatenates the string src in dst after the content of dst.
**
** @param	dst		=> the destination string.
** @param	src		=> the string to concatenate in dst.
** @param	size	=> the length of writable area dst.
**
** @return	the result of adding the lengths of dst and src,
** or the result of adding the lengths of dst and size if size is less than or
** equal to the length of dst.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dst_len)
		return (size + src_len);
	while (size && (size - dst_len - 1) && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
		size--;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
