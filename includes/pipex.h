/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:29:17 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/24 04:06:37 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

# define PATH_NOT_FOUND 127

typedef struct s_pipex
{
	int		fds[2];
	int		pipe_fds[2];
	char	**cmd1;
	char	**cmd2;
	int		ac;
	char	**av;
	char	**envp;
	pid_t	parent;
}				t_pipex;

int		pipex(t_pipex *p);
int		exit_and_free(t_pipex *p, int status);
void	free_tab(char **cmd);
int		init_struct(t_pipex **p, int ac, char **av, char **envp);
char	*get_cmd_file(char *cmd, char **envp);
char	*find_path(char *cmd, char **paths);
char	*get_paths(char **envp);
int		print_error(char *s1, char *s2, int status);

#endif
