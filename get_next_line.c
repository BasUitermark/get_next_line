#include "get_next_line.h"

void	remainder(char *str)
{
}

char	*desect_str(char *str)
{
	char	*out;
	size_t	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	out = ft_substr(str, 0, i + 1);
	return (out);
}

char	*read_data(int fd)
{
	char	*readstr;
	char	*out;
	int		b_read;
	char	BUFF[BUFFER_SIZE + 1];

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
	out = desect_str(readstr);
	return (out);
	// Check remainder or current readstr...
}

char	*get_next_line(int fd)
{
	char	*out;

	out = read_data(fd);
	return (out);
}
