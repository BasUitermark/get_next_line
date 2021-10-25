#include "get_next_line.h"

size_t	ft_strclen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i + 1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*out;

	i = ft_strclen(s1, '\0');
	j = ft_strclen(s2, '\0');
	if (!s1)
		return (ft_strdup(s2));
	out = (char *)malloc((i + j + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1, i + 1);
	ft_strlcpy(&out[i], s2, j + 1);
	out[i + j] = '\0';
	free((void *)s1);
	return (out);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	srclen;
	size_t	i;

	i = 0;
	srclen = ft_strclen(src, '\0');
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i + 1] = '\0';
	return (srclen);
}

char	*ft_strdup(const char *str)
{
	char	*out;

	out = (char *)ft_calloc(ft_strclen(str, '\0') + 1, sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, str, ft_strclen(str, '\0') + 1);
	return (out);
}
