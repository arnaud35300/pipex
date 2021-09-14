/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:50:38 by arguilla          #+#    #+#             */
/*   Updated: 2021/01/08 09:28:56 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check if a character is in the ascii table.
**
** @param	c	=> the character will be compared.
**
** @return	boolean value.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
