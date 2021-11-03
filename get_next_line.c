#include "get_next_line.h"

static char	*return_back(char *str)
{
	char	*remainder;
	size_t	start;
	size_t	i;

	i = 0;
	start = 0;
	while (str[start - 1] != '\n' && str[start])
		start++;
	while (str[start + i])
		i++;
	remainder = ft_substr(str, start, i);
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
	return (out);
}

// static char	*read_data(int fd)
// {

// }

char	*get_next_line(int fd)
{
	char		*readstr;
	char		*out;
	int			b_read;
	char		BUFF[BUFFER_SIZE + 1];
	static char	*remainder;

	b_read = 1;
	readstr = NULL;
	if (fd < 0 || fd > 1024)
		return (NULL);
	while (b_read > 0)
	{
		b_read = read(fd, BUFF, BUFFER_SIZE);
		BUFF[b_read] = '\0';
		readstr = ft_strjoin(readstr, BUFF);
		if (ft_strchr(BUFF, '\n') || b_read < BUFFER_SIZE)
		{
			out = ft_strjoin(remainder, return_front(readstr));
			free(readstr);
			remainder = return_back(BUFF);
			return (out);
		}
	}
	if (remainder)
	{
		readstr = ft_strdup(remainder);
		free(remainder);
		remainder = NULL;
		out = return_front(remainder);
		remainder = return_back(readstr);
		return (out);
	}
	return (NULL);
}
