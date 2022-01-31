/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 10:39:10 by buiterma      #+#    #+#                 */
/*   Updated: 2022/01/31 11:25:35 by buiterma      ########   odam.nl         */
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

static char	*read_data(int fd, t_data_store_gnl *store)
{
	char	buff[BUFFER_SIZE + 1];
	int		b_read;
	char	*line;

	while (true)
	{
		if (ft_strchr_gnl(store->readstr, '\n'))
			break ;
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read <= 0)
			break ;
		buff[b_read] = '\0';
		store->readstr = ft_strappend_gnl(store->readstr, buff);
	}
	if (store->readstr)
	{
		line = ft_get_line(store->readstr);
		if (ft_strlen_gnl(ft_strchr_gnl(store->readstr, '\n')) != 0)
			store->r_main = ft_strdup_gnl(ft_strchr_gnl(store->readstr, '\n'));
		free(store->readstr);
		store->readstr = NULL;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_data_store_gnl	store;

	if (read(fd, NULL, 0) == -1)
		return (NULL);
	if (fd >= 0 && fd <= 1024 && BUFFER_SIZE > 0)
	{
		if (store.r_main)
		{
			store.readstr = ft_strdup_gnl(store.r_main);
			free(store.r_main);
			store.r_main = NULL;
		}
		return (read_data(fd, &store));
	}
	return (NULL);
}
