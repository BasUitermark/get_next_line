#include "get_next_line.h"

static char	*get_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (ft_substr(str, 0, i + 1));
}

static char	*read_data(int fd, t_data_store *store)
{
	char	BUFF[BUFFER_SIZE + 1];
	int		b_read;
	char	*get;

	b_read = 1;
	while (b_read > 0)
	{
		if (ft_strchr(store->readstr, '\n') || ft_strchr(store->readstr, '\0'))
			break ;
		b_read = read(fd, BUFF, BUFFER_SIZE);
		if (b_read <= 0)
			break ;
		BUFF[b_read] = '\0';
		store->readstr = ft_strjoin(store->readstr, BUFF);
	}
	if (store->readstr)
	{
		get = get_line(store->readstr);
		store->r_main = ft_strdup(ft_strchr(store->readstr, '\n'));
		free(store->readstr);
		return (get);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_data_store	store;

	store.readstr = NULL;
	if (fd >= 0 && fd <= 1024 && BUFFER_SIZE > 0)
	{
		if (store.r_main)
		{
			store.readstr = ft_strdup(store.r_main);
			free(store.r_main);
		}
		return (read_data(fd, &store));
	}
	return (NULL);
}
