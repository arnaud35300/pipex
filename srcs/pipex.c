/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 02:53:25 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/24 18:21:01 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	child_process(t_pipex *p)
{
	char	*path;
	int		r;

	r = 1;
	path = get_cmd_file(p->cmd1[0], p->envp);
	dup2(p->pipe_fds[1], 1);
	dup2(p->fds[0], 0);
	close(p->pipe_fds[0]);
	close(p->pipe_fds[1]);
	if (!path)
		print_file_error(p->cmd2[0], "command not found");
	else if (path && access(path, R_OK | X_OK) == 1)
		print_file_error(p->cmd2[0], "permission denied.");
	else
		execve(path, p->cmd1, p->envp);
	exit_and_free(p, 0);
	if (!path)
		r = PATH_NOT_FOUND;
	else if (path && access(path, R_OK | X_OK) == -1)
		r = 126;
	if (path)
		free(path);
	exit(r);
}

static int	parent_process(t_pipex *p)
{
	char	*path;
	int		r;

	r = 1;
	path = get_cmd_file(p->cmd2[0], p->envp);
	dup2(p->fds[1], 1);
	dup2(p->pipe_fds[0], 0);
	close(p->pipe_fds[0]);
	close(p->pipe_fds[1]);
	if (!path)
		print_file_error(p->cmd2[0], "command not found");
	else if (path && access(path, R_OK | X_OK) == -1)
		print_file_error(p->cmd2[0], "permission denied.");
	else
		execve(path, p->cmd2, p->envp);
	if (!path)
		r = PATH_NOT_FOUND;
	else if (access(path, R_OK | X_OK) == -1)
		r = 126;
	if (path)
		free(path);
	return (r);
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
