/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:27:52 by arguilla          #+#    #+#             */
/*   Updated: 2021/01/08 09:21:06 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Convert string to integer.
**
** @param	str	=> the string to be converted.
**
** @return	a number representing the conversion of the string, 0 if string
** is not convertible.
*/

int	ft_atoi(const char *str)
{
	int	r;
	int	s;

	r = 0;
	s = 1;
	while (*str == 32 || (*str >= 8 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + *str - 48;
		str++;
	}
	return (r * s);
}
