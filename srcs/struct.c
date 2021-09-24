/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 02:58:24 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/23 20:24:11 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	print_file_error(char *filename, char *error)
{
	ft_putstr_fd("pipex : ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
}

int	init_struct(t_pipex **p, int ac, char **av, char **envp)
{
	*p = malloc(sizeof(t_pipex));
	if (!(*p))
		return (0);
	(*p)->fds[0] = open(av[1], O_RDONLY);
	if ((*p)->fds[0] < 0)
		print_file_error(av[1], strerror(errno));
	(*p)->fds[1] = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if ((*p)->fds[1] < 0)
		print_file_error(av[4], strerror(errno));
	(*p)->cmd1 = ft_split(av[2], ' ');
	(*p)->cmd2 = ft_split(av[3], ' ');
	(*p)->ac = ac;
	(*p)->av = av;
	(*p)->envp = envp;
	if (!(*p)->cmd1 || !(*p)->cmd2)
		return (0);
	return (1);
}
