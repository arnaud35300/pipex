/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:16:38 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/24 04:05:50 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	*p;

	if (ac != 5)
		return (print_error("Usage: ./pipex infile cmd1 cmd2 outfile\n",
				"", 1));
	if (!init_struct(&p, ac, av, envp))
		return (exit_and_free(p, 1));
	return (exit_and_free(p, pipex(p)));
}
