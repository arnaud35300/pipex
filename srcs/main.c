#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef	struct	s_pipex
{
	int		file1;
	int		file2;
	char	*cmd1;
	char	*cmd2;
}				t_pipex;

int	main(int ac, char **av, char **envp)
{
	int result;
	const char	*filename = "/mnt/nfs/homes/arguilla/Documents/pipex/test";
	int fd = open(filename, O_WRONLY | O_APPEND);
	
	execve("/usr/bin/grep pipe", av, NULL);
}
