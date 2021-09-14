/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:53:24 by arguilla          #+#    #+#             */
/*   Updated: 2021/01/08 11:05:49 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Same as memcpy but memmove ensure it handles the overlap correctly.
*/

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if ((char *)dest > (char *)src)
		while (len--)
			*(char *)(dest + len) = *(char *)(src + len);
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
