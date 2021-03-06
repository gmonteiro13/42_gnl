#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


char			*check_re(char *re, char **line)
{
	char 	*n_p;
	char	*re_init;

	re_init = re;
	n_p = NULL;
	if (re_init)
	{
		if ((n_p = ft_strchr(re, '\n')))
		{
			*n_p = '\0';
			*line = ft_strdup(re);
			ft_strcpy(re_init, ++n_p);
		}
		else
		{
			*line = ft_strdup(re_init);
			ft_strbzero(re_init);
		}
	}
	else
	{
		*line = ft_strnew(1);
	}
	return (n_p);
}

int				get_line(int fd, char **line, char *re)
{
	char		buf[BUFF_SIZE + 1];
	int			byte_read;
	char		*n_p;
	static char	*re;
	char		*tmp;

	n_p = check_re(re, line);
	while (!n_p && (byte_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[byte_read] = '\0';
		if ((n_p = ft_strchr(buf, '\n')))
		{
			*n_p = '\0';
			n_p++;
			re = ft_strdup(n_p);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return (byte_read || ft_strlen(*line)) ? 1 : 0;
}

int				get_nextline(int fd, char **line)
{
	
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
