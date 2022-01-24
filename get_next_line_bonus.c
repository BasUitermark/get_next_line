#include "get_next_line.h"

static char	*get_line(char *readstr)
{
	size_t	i;

	i = 0;
	while (readstr[i] != '\n' && readstr[i])
		i++;
	return (ft_substr(readstr, 0, i + 1));
}

static char	*read_data(int fd, t_data_store *store)
{
	char	buff[BUFFER_SIZE + 1];
	int		b_read;
	char	*line;

	b_read = 1;
	while (b_read > 0)
	{
		if (ft_strchr(store->readstr, '\n') || ft_strchr(store->readstr, '\0'))
			break ;
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read <= 0)
			break ;
		buff[b_read] = '\0';
		store->readstr = ft_strjoin(store->readstr, buff);
	}
	if (store->readstr)
	{
		line = get_line(store->readstr);
		if (ft_strlen(ft_strchr(store->readstr, '\n')) != 0)
			store->r_main = ft_strdup(ft_strchr(store->readstr, '\n'));
		free(store->readstr);
		store->readstr = NULL;
		return (line);
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
		if (store.r_main)
		{
			store.readstr = ft_strdup(store.r_main);
			free(store.r_main);
			store.r_main = NULL;
		}
		return (read_data(fd, &store));
	}
	return (NULL);
}
