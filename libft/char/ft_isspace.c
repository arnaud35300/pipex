/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:36:43 by arguilla          #+#    #+#             */
/*   Updated: 2021/08/24 22:43:07 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check if a character si a space.
**
** @param	c	=> the character will be compared.
**
** @return	boolean value.
*/

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == ' ');
}
