/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 03:33:53 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/07 01:26:40 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function converts the initial part of the string in nptr to a long
** integer value according to the given base, which must be between 2 and 36
** inclusive, or be the special value 0. See the strtol man.
** The status parameters have the same role as the errno.
** If status isn't 0, this means that errors.
**
** @return long	=> The result of the conversion.
*/

static void	skip_spaces(const char **s)
{
	while (**s == ' ')
		(*s)++;
}

static void	check_sign(const char **s, int *sign)
{
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*sign = -1;
		 (*s)++;
	}
}

static void	check_base(const char **s, int *base)
{
	if (**s)
		*base = 10;
}

static int	check_overflow(char c, long long r, int sign)
{
	if (sign == -1)
		if ((r * 10 + c - 48) * sign < INT_MIN)
			return (0);
	if (sign == 1)
		if ((r * 10 + c - 48) * sign > INT_MAX)
			return (0);
	return (1);
}

int	ft_strtol(const char *nptr, char **endptr, int base, int *err)
{
	const char		*s;
	int				sign;
	long long		r;

	s = nptr;
	sign = 1;
	*err = 1;
	r = 0;
	skip_spaces(&s);
	check_sign(&s, &sign);
	check_base(&s, &base);
	while (ft_isdigit(*s))
	{
		*err = 0;
		if (check_overflow(*s, r, sign))
			r = r * base + *s - 48;
		else
			*err = 1;
		s++;
	}
	*endptr = (char *) s;
	if (*err >= 1)
		*endptr = (char *) nptr;
	return ((int)(r * sign));
}
