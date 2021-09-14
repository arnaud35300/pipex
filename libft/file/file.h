/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 00:04:47 by arguilla          #+#    #+#             */
/*   Updated: 2021/08/23 01:19:12 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# define FDMAX 257

size_t	ft_strlen_g(const char *s);
int		check_line(char *str);
char	*ft_substr_g(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_g(char const *s1, char const *s2);
int		negpos(int pos, char **str);
int		get_next_line(int fd, char **line);

#endif
