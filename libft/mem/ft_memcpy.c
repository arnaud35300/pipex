/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:53:14 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:07:29 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies n bytees from memory area src to memory area dst.
**
** @param	dest	=> the memory area destination.
** @param	src		=> the memory area source.
** @param	n		=> the syze to memory area will be copied.
**
** @return	the original value of dst.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*r;

	r = dest;
	while (n)
	{
		*(char *)dest = *(char *)src;
		src++;
		dest++;
		n--;
	}
	return (r);
}
