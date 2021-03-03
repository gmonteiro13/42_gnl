#include "get_next_line.h"

char			*ft_strdup(const char *s)
{
	size_t		s_len;
	char		*dup;

	s_len = ft_strlen(s);
	dup = (char *)malloc(s_len + 1);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s, s_len + 1);
	return (dup);
}

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

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

size_t			ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		i += 1;
	}
	return (i);
}
