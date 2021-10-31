#include "get_next_line.h"

static char	*return_back(char *str)
{
	char	*remainder;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	while (len > 0 && str[len] != '\n')
	{
		len--;
		i++;
	}
	remainder = ft_substr(str, len + 1, i - 1);
	return (remainder);
}

static char	*return_front(char *str)
{
	char	*out;
	size_t	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	out = ft_substr(str, 0, i);
	return (out);
}

static char	*read_data(int fd)
{
	char		*readstr;
	char		*out;
	int			b_read;
	char		BUFF[BUFFER_SIZE + 1];
	static char	*remainder;
	char		*tmp;

	b_read = 1;
	readstr = NULL;
	while (b_read > 0)
	{
		b_read = read(fd, BUFF, BUFFER_SIZE);
		BUFF[b_read] = '\0';
		readstr = ft_strjoin(readstr, BUFF);
		if (ft_strchr(BUFF, '\n'))
			break ;
	}
	if (remainder)
	{
		out = ft_strdup(remainder);
		free(remainder);
	}
	tmp = disect_str(readstr);
	out = ft_strjoin(out, tmp);
	remainder = remainder_str(readstr);
	free(readstr);
	free(tmp);
	return (out);
}

/**
 * TODO
 * missing letters on multiple single character lines
 * segfault on one single character line
 * keeps printing even when everything is read
 * make main to test betters
 */

char	*get_next_line(int fd)
{
	char	*out;

	out = read_data(fd);
	return (out);
}
