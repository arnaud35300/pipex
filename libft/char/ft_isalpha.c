/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:23:07 by arguilla          #+#    #+#             */
/*   Updated: 2021/01/08 09:27:55 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check if a character is alphanumeric (lower or upper case).
**
** @param	c	=> the character will be compared.
**
** @return	boolean value.
*/

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
