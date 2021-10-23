#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFFER_SIZE 14

char *get_next_line(int fd);
size_t	ft_strlen(const char *str);

#endif