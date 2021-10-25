#include "get_next_line.h"
/*
If there is no new line, store in buffer and read again.
If there is a new line, store overflow in buffer.
*/

void read_data(int fd)
{
	char	*readstr;
	int		b_read;
	char	BUFF[BUFFER_SIZE + 1];

	b_read = 1;
	readstr = NULL;
	while (b_read > 0)
	{
		b_read = read(fd, BUFF, BUFFER_SIZE);
		BUFF[b_read] = '\0';
		readstr = ft_strjoin(readstr, BUFF); // if s1 is null, return strdup s2
	}
	remainder = ft_splitup() // use substring to split up 
	// Check current string for remainder
	// Check remainder or current readstr...
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*read_str;
	char	*temp;
	size_t	read_size;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	read_str = (char *)malloc((BUFFER_SIZE) * sizeof(char));
	if (!read_str)
		return (NULL);
	read_size = read(fd, read_str, BUFFER_SIZE);
	temp = (char *)malloc((read_size + 2) * sizeof(char));
	if (!temp)
		return (NULL);
	while (read_str[i])
	{
		temp[j] = read_str[i];
		i++;
		j++;
		if (read_str[i] == '\n')
		{
			temp[j + 1] = '\0';
			return (temp);
		}
	}
	return (NULL);
}
/*
1.	Read fd for BUFFER_SIZE amount of charachters.
2.	Count characters in read_str untill newline.
	*	If read_size is equal in length to read_str
		append buffer and return
	*	If 

*/