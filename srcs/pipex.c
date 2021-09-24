/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 02:53:25 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/24 04:13:37 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	child_process(t_pipex *p)
{
	char	*path;

	path = get_cmd_file(p->cmd1[0], p->envp);
	dup2(p->pipe_fds[1], 1);
	dup2(p->fds[0], 0);
	close(p->pipe_fds[0]);
	close(p->pipe_fds[1]);
	if (!path)
		print_error(p->cmd1[0], ": command not found\n", 0);
	else
		execve(path, p->cmd1, p->envp);
	free(path);
	exit_and_free(p, 0);
	if (!path)
		exit(PATH_NOT_FOUND);
	exit(1);
}

static int	parent_process(t_pipex *p)
{
	char	*path;

	path = get_cmd_file(p->cmd2[0], p->envp);
	dup2(p->fds[1], 1);
	dup2(p->pipe_fds[0], 0);
	close(p->pipe_fds[0]);
	close(p->pipe_fds[1]);
	if (!path)
		print_error(p->cmd2[0], ": command not found\n", 0);
	else
		execve(path, p->cmd2, p->envp);
	if (path)
		free(path);
	if (!path)
		return (PATH_NOT_FOUND);
	return (1);
}

int	pipex(t_pipex *p)
{
	pid_t	process;

	if (pipe(p->pipe_fds) == -1)
		return (0);
	process = fork();
	if (process < 0)
		return (0);
	if (process == 0 && p->fds[0] > 0)
		child_process(p);
	else if (process != 0 && p->fds[1] > 0)
		return (parent_process(p));
	return (1);
}
