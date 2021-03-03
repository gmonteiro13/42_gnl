#include "get_next_line.h"

char				*ft_strdup(const char *s)
{
	size_t			s_len;
	char			*dup;

	s_len = ft_strlen(s);
	dup = (char *)malloc(s_len + 1);
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

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_str == NULL)
		return (NULL);
	while (*s1)
	{
		new_str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		new_str[i] = *s2;
		i++;
		s2++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void				*ft_memset(void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (n > i)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

char				*ft_strchr(const char *s, int c)
{
	const char 		*p;

	p = s;
	while (*p + 1)
	{
		if (*p == c)
		{
			return (char *)p;
		}
		if (*p == '\0')
		{
			return (NULL);
		}
		p++;
	}
	return (NULL);
}
