#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

static int				get_line(char **line, char **save, char *n_p)
{
	char *tmp;

	if (n_p != NULL)
	{
		*line = ft_strdup(*save);
		tmp = ft_strdup(n_p + 1);
		free(*save);
		*save = tmp;
		return (1);
	}
	if (*save != NULL)
	{
		*line = *save;
		*save = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char 		buf[BUFF_SIZE + 1];
	int 		byte_read;
	char 		*n_p;
	static char *re[1000];
	char 		*tmp;

	if ((fd < 0)
			|| (line == 0) || (BUFF_SIZE <= 0)
			|| (read(fd, buf, 0) < 0)
			|| !(*line = ft_strdup("")))
		return (-1);
	n_p = ft_strchr(re[fd], '\n');
	byte_read = read(fd, buf, BUFF_SIZE);
	while ((n_p == 0) && (byte_read > 0))
	{
		buf[byte_read] = 0;
		tmp = re[fd];
		if (tmp == NULL)
			ft_strdup(buf);
		else
			ft_strjoin(re[fd], buf);
		if (re != 0)
			free(re[fd]);
		re[fd] = tmp;
	}
	if (byte_read < 0)
		return (-1);
	return (get_line(line, &re[fd], n_p));
}

// int	main(void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("text.txt", O_RDONLY);
// 	get_next_line(fd, &line);
// 	printf("%s\n", line);
// 	get_next_line(fd, &line);
// 	printf("%s\n", line);
// }
