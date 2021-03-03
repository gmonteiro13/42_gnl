#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


int	get_next_line(int fd, char **line)
{
	char	buf[10 + 1];

	read(fd, buf, 10);
	// buf[10] = '\0';
	*line = ft_strdup(buf);
	return (0);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
}
