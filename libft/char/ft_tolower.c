/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:16:57 by arguilla          #+#    #+#             */
/*   Updated: 2021/01/08 13:53:17 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Change letters from uppercase to lowercase.
**
** @param	c	=> the character to change.
**
** @return the uppercase character.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
