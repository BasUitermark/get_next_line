/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 10:39:04 by buiterma      #+#    #+#                 */
/*   Updated: 2022/01/31 11:24:43 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strappend_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*out;

	i = -1;
	j = -1;
	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	if (!s1)
		return (ft_strdup_gnl(s2));
	out = (char *)malloc(len1 + len2 + 1 * sizeof(char));
	if (!out)
		return (NULL);
	while (s1[++i])
		out[i] = s1[i];
	while (s2[++j])
		out[i + j] = s2[j];
	out[i + j] = '\0';
	free(s1);
	return (out);
}

char	*ft_strdup_gnl(char *str)
{
	char	*out;
	int		i;
	int		len;

	len = 0;
	if (str)
		len = ft_strlen_gnl(str);
	i = 0;
	if (!str)
		return (NULL);
	out = (char *)malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	while (str[i])
	{
		out[i] = str[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_strchr_gnl(char *str, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!str || !c)
		return (NULL);
	len = ft_strlen_gnl(str);
	if (c == '\0')
		return (&((char *)str)[len]);
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (&((char *)str)[i + 1]);
		i++;
	}
	return (NULL);
}

char	*ft_substr_gnl(char*s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (start > ft_strlen_gnl(s))
		return (ft_strdup_gnl(""));
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
