/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:16:38 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/17 23:55:12 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
typedef	struct	s_pipex
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

void	free_cmd(char **cmd)
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
	if (p->fds[0] < 0)
		ft_putstr_fd("No such file or directory.\n", 2);
	free_cmd(p->cmd1);
	free_cmd(p->cmd2);
	free(p);
	return (status);
}

int	init_struct(t_pipex **p, int ac, char **av, char **envp)
{
	*p = malloc(sizeof(t_pipex));
	if (!(*p))
		return (0);
	(*p)->fds[0] = open(av[1], O_RDONLY);
	(*p)->fds[1] = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	(*p)->cmd1 = ft_split(av[2], ' ');
	(*p)->cmd2 = ft_split(av[3], ' ');
	(*p)->ac = ac;
	(*p)->av = av;
	(*p)->envp = envp;
	if ((*p)->fds[0] < 0 || !(*p)->cmd1 || !(*p)->cmd2)
		return (0);
	return (1);
}

int	pipex(t_pipex *p)
{
	if (pipe(p->pipe_fds) == -1)
		return (0);
	/*dup2(p->pipe_fds[0], 1);
	printf("hey\n");
	//write(p->pipe_fds[1], "123\n", 4);
	char buffer[4];
	read(p->pipe_fds[0],  buffer, 4);
	printf("%s\n", buffer);
	*/
	pid_t parent;

	int i = -1;
	parent = fork();
	if (parent == 0)
	{
		i = 1;
		printf("enfant: %d\n", i);
		fflush(stdout);
	} else {
		i = 2;
		wait(NULL);
		printf("parent: %d\n", i);
		fflush(stdout);
	}
	printf("\nfin: %d\n", i);
	fflush(stdout);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*p;

	if (ac != 5)
		return (1);
	if (!init_struct(&p, ac, av, envp))
		return (exit_and_free(p, 1));
	if (!pipex(p))
		return (exit_and_free(p, 1));
	return (exit_and_free(p, 0));
}
