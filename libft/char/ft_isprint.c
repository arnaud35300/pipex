/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:43:28 by arguilla          #+#    #+#             */
/*   Updated: 2021/01/08 09:29:42 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check if a character is a printable character.
**
** @param	c	=> the character will be compared.
**
** @return	boolean value.
*/

int	ft_isprint(int c)
{
	return (c > 31 && c < 127);
}
