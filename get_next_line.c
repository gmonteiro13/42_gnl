#include "get_next_line.h"

char			*file_rd(int fd, char *re, char *buf)
{
	int			size;

	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		re = ft_strjoin(re, buf);
		if (ft_find_nl(re))
			return (re);
	}
	return (re);
}

int				get_line(char **line, char **re, char *n_p)
{
	char		*tmp;

	if (!n_p)
	{
		*line = ft_strdup(*re);
		free(*re);
		*re = NULL;
		return (0);
	}
	*n_p = '\0';
	n_p++;
	*line = ft_strdup(*re);
	if (!n_p)
	{
		free(*re);
		*re = NULL;
		return (1);
	}
	tmp = ft_strdup(n_p);
	free(*re);
	*re = tmp;
	return (1);
}

int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		*n_p;
	static char *re[MAX_FD];

	if ((fd < 0)
	|| (line == 0) || (BUFFER_SIZE <= 0)
	|| (read(fd, buf, 0) < 0) || !(*line = ft_strdup("")))
		return (-1);
	if (!(re[fd] = file_rd(fd, re[fd], buf)))
		return (0);
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	n_p = ft_find_nl(re[fd]);
	return (get_line(line, &re[fd], n_p));
}
