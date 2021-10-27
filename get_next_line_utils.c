#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*out;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	out = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!out)
		return (NULL);
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		out[i + j] = s2[j];
		j++;
	}
	out[i + j] = '\0';
	free((void *)s1);
	return (out);
}

char	*ft_strdup(const char *str)
{
	char	*out;
	size_t	i;

	i = 0;
	out = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!out)
		return (NULL);
	while (str[i])
	{
		out[i] = str[i];
		i++;
	}
	return (out);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	len;

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
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (j < len && s[i])
	{
		sub[j] = s[i];
		j++;
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
