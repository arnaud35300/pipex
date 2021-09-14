/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 21:12:31 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:06:03 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Free and re-allocate a string with NULL.
**
** @param	str	=> the string to free and realloc.
**
** @return	int.
*/

int	negpos(int pos, char **str)
{
	if (pos == 0)
	{
		if (str)
		{
			free(*str);
			*str = NULL;
		}
		return (0);
	}
	return (1);
}

/*
** Read file line per line while EOF is not read.
**
** @param	fd		=> the file descriptor.
** @param	line	=> the line which store the current line of file value.
**
** @return	int.
*/

int	get_next_line(int fd, char **line)
{
	static char		*tab[FDMAX];
	char			buffer[BUFFER_SIZE + 1];
	char			*tmp;
	int				pos;

	pos = -1;
	if (fd < 0 || fd > FDMAX || read(fd, 0, 0) < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while (-1 == check_line(tab[fd]) && pos != 0)
	{
		pos = read(fd, buffer, BUFFER_SIZE);
		buffer[pos] = '\0';
		tmp = tab[fd];
		tab[fd] = ft_strjoin_g(tab[fd], buffer);
		free(tmp);
	}
	*line = ft_substr_g(tab[fd], 0, check_line(tab[fd]));
	tmp = tab[fd];
	tab[fd] = ft_substr_g(tab[fd], check_line(tab[fd]) + 1,
			ft_strlen_g(tab[fd]));
	free(tmp);
	return (negpos(pos, &tab[fd]));
}
