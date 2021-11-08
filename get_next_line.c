#include "get_next_line.h"

// char	*get_line(char *str)
// {
// 	char	*out;
// 	size_t	i;

// 	i = 0;
// 	while (str[i - 1] != '\n' && str[i])
// 		i++;
// 	out = ft_substr(str, 0, i);
// 	return (out);
// }

char	*read_data(int fd, t_data_store *store)
{
	char	BUFF[BUFFER_SIZE + 1];
	int		b_read;

	b_read = 1;
	store->readstr = NULL;
	while (b_read > 0)
	{
		b_read = read(fd, BUFF, BUFFER_SIZE);
		if (b_read < 0 || b_read < BUFFER_SIZE)
			break ;
		BUFF[b_read] = '\0';
		store->readstr = ft_strjoin(store->readstr, BUFF);
		printf("readstr: %s\n", store->readstr);
		// if (ft_strchr(store->readstr, '\n'))
		// 	return (get_line(store->readstr));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_data_store	store;

	if (read(fd, NULL, 0) == -1)
		return (NULL);
	if (fd >= 0 && fd <= 1024 && BUFFER_SIZE > 0)
	{
		// if (ft_strchr(store.r_main, '\n'))
		// 	return (get_line(store.r_main));
		return (read_data(fd, &store));
	}
	return (NULL);
}
