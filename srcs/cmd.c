/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 02:59:29 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/24 00:55:56 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_paths(char **envp)
{
	while (envp && *envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	if (envp && *envp)
		return (ft_substr(*envp, 5, ft_strlen(*envp) - 5));
	return (NULL);
}

char	*find_path(char *cmd, char **paths)
{
	char	*path;
	char	*prefixed;
	int		i;

	i = -1;
	prefixed = ft_strjoin("/", cmd);
	while (paths && paths[++i])
	{
		path = ft_strjoin(paths[i], prefixed);
		if (path && access(path, F_OK) == 0)
		{
			free(prefixed);
			return (path);
		}
		if (path)
			free(path);
	}
	if (prefixed)
		free(prefixed);
	if (cmd && access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

char	*get_cmd_file(char *cmd, char **envp)
{
	char	*line;
	char	*path;
	char	**paths;

	line = get_paths(envp);
	paths = ft_split(line, ':');
	if (line)
		free(line);
	path = find_path(cmd, paths);
	free_tab(paths);
	return (path);
}
