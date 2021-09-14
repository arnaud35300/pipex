#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(void)
{
	int result;
	const char	*filename = "/mnt/nfs/homes/arguilla/Documents/pipex/test";
	int fd = open(filename, O_WRONLY | O_APPEND);
	dup2(fd, 1);
	printf("bonjour");
}
