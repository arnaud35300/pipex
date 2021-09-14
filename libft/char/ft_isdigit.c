/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:30:08 by arguilla          #+#    #+#             */
/*   Updated: 2021/01/08 09:29:22 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check if a character is a digit number.
**
** @param	c	=> the character will be compared.
**
** @return	boolean value.
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
