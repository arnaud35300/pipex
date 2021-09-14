/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 00:01:13 by arguilla          #+#    #+#             */
/*   Updated: 2021/01/29 07:37:19 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates memory for an array of count elements of size bytes.
** The memory is set to zero.
**
** @param	count	=> the length of array.
** @param	size	=> the size of each array value.
**
** @return	pointer to the allocated, NULL if malloc fails.
*/

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*buffer;

	buffer = malloc(count * size);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, (count * size));
	return ((void *)buffer);
}
