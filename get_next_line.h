#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#define MAX_FD 4096

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *source);
char	*strjoin(char *s1, char *s2);
void 	*ft_memcpy(void *dest, const void *src, size_t n);
char 	*ft_strchr_nl(char *s);
char 	*ft_strchr(const char *s, int c);

#endif
