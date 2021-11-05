#include "get_next_line.h"

char	*get_line(data_store *store)
{
	//TODO gets line and saves remainder;
	/**
	 * if (ft_strchr(store->r_main, '\n'))
	 * 		ft_strjoin(store->r_main, store->data)
	 * 		
	 * else
	 * 
	 * 
	 * 
	*/
}

char	*read_data(int fd, data_store *store)
{
	char		BUFF[BUFFER_SIZE + 1];
	int			b_read;

	b_read = 1;
	store->readstr = NULL;
	while (b_read > 0)
	{
		b_read = read(fd, BUFF, BUFFER_SIZE);
		BUFF[b_read] = '\0';
		store->readstr = ft_strjoin(store->readstr, BUFF);
		if (ft_strchr(store->readstr, '\n'))
			return (get_line(&store));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	data_store	store;

	if (read(fd, NULL, 0) == -1)
		return (NULL);
	if (fd >= 0 && fd <= 1024 && BUFFER_SIZE > 0)
	{
		if (ft_strchr(store.r_main, '\n'))
			return (get_line(&store));
		return (read_data(fd, &store));
	}
	return (NULL);
}
