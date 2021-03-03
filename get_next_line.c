#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	get_next_line(int fd, char **line)
{
	char	c;
	
	read(fd, &c, 1);
	return (0);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
}
