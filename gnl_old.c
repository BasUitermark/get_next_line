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
	// printf("return_back: %s\n", remainder);
	return (remainder);
}

static char	*return_front(char *str)
{
	char	*out;
	size_t	i;

	i = 0;
	while (str[i - 1] != '\n' && str[i])
		i++;
	out = ft_substr(str, 0, i);
	// printf("return_front: %s\n", out);
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
	while (b_read > 0 && !(ft_strchr(BUFF, '\n')))
	{
		if (remainder)
		{
			readstr = ft_strdup(remainder);
			free(remainder);
		}
		b_read = read(fd, BUFF, BUFFER_SIZE);
		BUFF[b_read] = '\0';
		readstr = ft_strjoin(readstr, BUFF);
	}
	// printf("readstr: %s\n", readstr);
	out = return_front(readstr);
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