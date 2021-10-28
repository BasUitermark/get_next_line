#include "get_next_line.h"

static char	*remainder_str(char *readstr)
{
	char	*remainder;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(readstr);
	while (len > 0 && readstr[len] != '\n')
	{
		len--;
		i++;
	}
	remainder = ft_substr(readstr, len + 1, i);
	return (remainder);
}

static char	*disect_str(char *readstr)
{
	char	*out;
	size_t	i;

	i = 0;
	while (readstr[i] != '\n' )
		i++;
	out = ft_substr(readstr, 0, i);
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
	out = NULL;
	while (b_read > 0)
	{
		b_read = read(fd, BUFF, BUFFER_SIZE);
		BUFF[b_read] = '\0';
		readstr = ft_strjoin(readstr, BUFF);
		if (ft_strchr(readstr, '\n'))
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

char	*get_next_line(int fd)
{
	char	*out;

	out = read_data(fd);
	return (out);
}
