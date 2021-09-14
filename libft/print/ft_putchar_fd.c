/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:53:00 by arguilla          #+#    #+#             */
/*   Updated: 2021/01/08 11:12:59 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Write one character in a file descriptor.
**
** @param	c	=> the character to write.
** @param	fd	=> the file descriptor.
**
** @return	void.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
