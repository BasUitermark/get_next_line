#include "get_next_line.h"

static char	*return_back(char *str)
{
	char	*remainder;
	size_t	start;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[start - 1] != '\n' && str[start])
		start++;
	while (str[start + i])
		i++;
	remainder = ft_substr(str, start, i - 1);
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

	b_read = 1;
	readstr = NULL;
	/*
	TODO
	recheck if there is a newline in remainder
	*/
	if (remainder)
	{
		readstr = ft_strdup(remainder);
		free(remainder);
	}
	while (b_read > 0 && !(ft_strchr(BUFF, '\n')))
	{
		b_read = read(fd, BUFF, BUFFER_SIZE);
		if (b_read == 0)
			break ;
		BUFF[b_read] = '\0';
		readstr = ft_strjoin(readstr, BUFF);
	}
	out = ft_strjoin(out, return_front(readstr));
	remainder = return_back(readstr);
	free(readstr);
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
