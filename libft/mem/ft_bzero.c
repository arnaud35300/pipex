/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:41:05 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:09:08 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Set n first bytes of the memory starting at the location pointed by s,
** by writting zeros ('\0') to that area.
**
** @param	s	=> the starting location
** @param	n	=> the syze of bytes to write.
**
** @return	void.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*buffer;

	i = 0;
	if (n > 0)
	{
		buffer = (unsigned char *) s;
		while (i < n)
		{
			buffer[i] = 0;
			i++;
		}
	}
}
