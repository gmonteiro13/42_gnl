#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_FD 8192

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2)
char	*ft_find_nl(char *s);

#endif
