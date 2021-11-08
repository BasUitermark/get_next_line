#include "get_next_line.h"

static char	*get_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (ft_substr(str, 0, i + 1));
}

static char	*get_save(char *str)
{
	char	*out;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	while (str[i + j])
		j++;
	return (ft_substr(str, i + 1, i + j + 1));
}

static char	*read_data(int fd, t_data_store *store)
{
	char	BUFF[BUFFER_SIZE + 1];
	int		b_read;
	char	*out;

	b_read = 1;
	while (b_read > 0)
	{
		if (ft_strchr(store->readstr, '\n'))
			break ;
		b_read = read(fd, BUFF, BUFFER_SIZE);
		// if (b_read == 0 && store->r_main)
		// 	return (get_line(store->r_main));
		BUFF[b_read] = '\0';
		store->readstr = ft_strjoin(store->readstr, BUFF);
		if (b_read < 0 || b_read < BUFFER_SIZE)
			break ;
	}
	out = ft_strjoin(store->r_main, get_line(store->readstr));
	store->r_main = get_save(store->readstr);
	free(store->readstr);
	return (out);
}

char	*get_next_line(int fd)
{
	static t_data_store	store;

	store.readstr = NULL;
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

/*
1. 
New read till a new line is found.
Return string till new line.
Save remainder.
2.

*/