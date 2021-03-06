#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#define BUFF_SIZE 40

int		get_next_line(int fd, char **line);
int 	get_line(int fd, char **line, char *re);

void ft_strbzero(char *s);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char 	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
char 	*ft_strchr(const char *s, int c);
char 	ft_strcpy(char *dest, const char *src);
void 	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
