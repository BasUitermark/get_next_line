/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 12:02:30 by buiterma      #+#    #+#                 */
/*   Updated: 2022/01/31 14:27:27 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/include/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

int	main(void)
{
	int		fd;
	FILE	*fp;
	char	*temp;
	char	*out;

	remove("testprint.txt");
	fd = open("test.txt", O_RDONLY);
	fp = fopen("testprint.txt", "w+");
	while (true)
	{
		temp = get_next_line(fd);
		if (temp)
		{
			out = ft_strappend(out, temp);
		}
		else
			break ;
		free(temp);
	}
	out = get_next_line(fd);
	fputs(out, fp);
	close(fd);
	fclose(fp);
	// system("leaks a.out");
	return (0);
}
