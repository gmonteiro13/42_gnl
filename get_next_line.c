#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


int	get_next_line(int fd, char **line)
{
	char	buf[10 + 1];
	int		byte_read;

	*line = ft_memset(*line, '\0', 1);
	while ((byte_read = read(fd, buf, 10)))
	{
		// if (ft_strchr(buf, '\n'))
		// {
		// 	break;
		// }
		buf[byte_read] = '\0';
		*line = ft_strjoin(*line, buf);
	}
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
