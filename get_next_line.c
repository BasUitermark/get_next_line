#include "get_next_line.h"

static char	*remainder_str(char *str)
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
	remainder = ft_substr(str, len, i);
	return (remainder);
}

static char	*disect_str(char *str)
{
	char	*out;
	size_t	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	out = ft_substr(str, 0, i + 1);
	return (out);
}

static char	*read_data(int fd)
{
	char		*readstr;
	char		*out;
	int			b_read;
	char		BUFF[BUFFER_SIZE + 1];
	char static	*remainder;

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
		out = ft_strjoin(out, remainder);
		free(remainder);
	}
	out = ft_strjoin(out, disect_str(readstr));
	remainder = remainder_str(readstr);
	free(readstr);
	return (out);
}

char	*get_next_line(int fd)
{
	char	*out;

	out = read_data(fd);
	return (out);
}
