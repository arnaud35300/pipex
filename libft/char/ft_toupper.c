/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:16:57 by arguilla          #+#    #+#             */
/*   Updated: 2021/01/08 13:53:42 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Change letters from lowercase to uppercase.
**
** @param	c	=> the character to change.
**
** @return the lowercase character.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
