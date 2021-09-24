/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 02:56:00 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/24 18:31:31 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **cmd)
{
	int	i;

	i = -1;
	if (!cmd)
		return ;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
}

int	exit_and_free(t_pipex *p, int status)
{
	if (!p)
		return (status);
	free_tab(p->cmd1);
	free_tab(p->cmd2);
	if (p->fds[0])
		close(p->fds[0]);
	if (p->fds[1])
		close(p->fds[1]);
	free(p);
	return (status);
}
