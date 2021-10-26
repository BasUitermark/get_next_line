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

	j = ft_strclen(s2, '\0');
	if (!s1)
		return (ft_strdup(s2));
	out = (char *)malloc(ft_strclen(s1, '\0') + ft_strclen(s2, '\0') + 1) * sizeof(char));
	if (!out)
		return (NULL);
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		out[i + j] = s2[j]
		j++;
	}
	out[i + j] = '\0';
	free((void *)s1);
	return (out);
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

char	*ft_strchr(const char *str, int c)
{
	t_size	i;
	t_size	len;

	i = 0;
	len = ft_strlen(str);
	if (c == '\0')
		return (&((char *)str)[len]);
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (&((char *)str)[i]);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	sub = (char *)ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	while (j < len && s[i])
	{
		sub[j] = s[i]
		j++;
		i++;
	}
	sub[j] = 0;
	return (sub);
}