/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:18:58 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:02:24 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Give the absolute value of a number
**
** @param	n	=> the number where we want to know its absolute value.
**
** @return	the absolute value of n.
*/

static int	get_absolute(int n)
{
	if (n > 0)
		return (n);
	return (-n);
}

/*
** Calculate the length of a number.
**
** @param	n	=> the number where we want to know its length.
**
** @return	the n length.
*/

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/*
** Convert int to string.
**
** @param	n	=> the number to be converted.
**
** @return	a string representing the conversion of the number, NULL
** if malloc fails.
*/

char	*ft_itoa(int n)
{
	char	*r;
	int		len;

	len = get_len(n);
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	r[len] = '\0';
	if (n == 0)
		r[0] = '0';
	else if (n < 0)
		r[0] = '-';
	while (n != 0)
	{
		--len;
		r[len] = get_absolute(n % 10) + '0';
		n = n / 10;
	}
	return (r);
}
