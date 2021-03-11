#include "get_next_line.h"

char				*ft_strdup(const char *s)
{
	size_t			s_len;
	char			*dup;

	s_len = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * (s_len + 1));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s, s_len + 1);
	return (dup);
}

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (dest);
	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		((char *)d)[i] = ((char *)s)[i];
		i++;
	}
	return (d);
}

size_t				ft_strlen(const char *str)
{
	size_t			i;

	i = 0;
	while (str[i] != '\0')
	{
		i += 1;
	}
	return (i);
}

char				*ft_strjoin(char *s1, char *s2)
{
	int				len_buf;
	int				len_rem;
	char			*result;
	int				i;
	int				j;

	if (!s1)
		return (ft_strdup(s2));
	len_rem = ft_strlen(s1);
	len_buf = ft_strlen(s2);
	if (!(result = (char *)malloc(sizeof(char) * (len_buf + len_rem + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	free(s1);
	result[i] = '\0';
	return (result);
}

char				*ft_find_nl(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (0);
}
