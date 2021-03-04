#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


char			*check_re(char *re, char **line)
{

}

int				get_next_line(int fd, char **line)
{
	char		buf[1000 + 1];
	int			byte_read;
	char		*null_p;
	int			flag;
	static char	*re;

	flag = 1;
	if (re)
		*line = ft_strdup(re);
	else
		*line = ft_memset(*line, '\0', 1);
	while (flag && (byte_read = read(fd, buf, 1000)))
	{
		buf[byte_read] = '\0';
		if ((null_p = ft_strchr(buf, '\n')))
		{
			*null_p = '\0';
			flag = 0;
			*null_p++;
			re = ft_strdup(null_p);
		}
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

	get_next_line(fd, &line);
	printf("%s\n", line);
}
