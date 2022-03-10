/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 10:39:10 by buiterma      #+#    #+#                 */
/*   Updated: 2022/03/10 18:00:12 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char *readstr)
{
	size_t	i;

	i = 0;
	while (readstr[i] != '\n' && readstr[i])
		i++;
	return (ft_substr_gnl(readstr, 0, i + 1));
}

static char	*ft_process(t_data_store_gnl *store)
{
	char	*line;

	line = ft_get_line(store->readstr);
	if (ft_strlen_gnl(ft_strchr_gnl(store->readstr, '\n')) != 0)
	{
		store->r_main = ft_strdup_gnl(ft_strchr_gnl(store->readstr, '\n'));
		if (!store->r_main)
			return (NULL);
	}
	free(store->readstr);
	store->readstr = NULL;
	return (line);
}

static char	*ft_read_data(int fd, t_data_store_gnl *store)
{
	static char	buff[BUFFER_SIZE + 1];
	int			b_read;

	b_read = 0;
	while (true)
	{
		if (ft_strchr_gnl(store->readstr, '\n'))
			break ;
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read < 0 && store->readstr)
		{
			free (store->readstr);
			store->readstr = NULL;
		}
		if (b_read <= 0)
			break ;
		buff[b_read] = '\0';
		store->readstr = ft_strappend_gnl(store->readstr, buff);
	}
	if (store->readstr)
		return (ft_process(store));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_data_store_gnl	store;

	if (read(fd, NULL, 0) != -1 && BUFFER_SIZE > 0)
	{
		if (store.r_main)
		{
			store.readstr = ft_strdup_gnl(store.r_main);
			free(store.r_main);
			store.r_main = NULL;
		}
		return (ft_read_data(fd, &store));
	}
	return (NULL);
}
