#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_data_store
{
	char	*readstr;
	char	*r_main;
}t_data_store;

//== get_next_line functions ==/

char		*get_next_line(int fd);

//== util functions ==//

/**
 * Checks the length of the string.
 * @param *str The string to be checked
 * @return Returns the lenght of the string
 */
size_t		ft_strlen(const char *str);

/**
 * Concatenates two string to one new string.
 * @param *s1 First string to concatenate.
 * @param *s2 Second string to concatenate.
 * @return Returns a new concatenated string.
 */
char		*ft_strjoin(char const *s1, char const *s2);

/**
 * Searches for the first occurence of c in str.
 * If str is empty or c = '\0' it gives back a pointer
 * to the end of str.
 * @param *str The string to search through.
 * @param c The character to search for.
 * @return Returns a pointer to c in str.
 */
char		*ft_strchr(const char *str, int c);

/**
 * Copies part of a string to a new string.
 * @param *s String to take from.
 * @param start Starting point where to copy from.
 * @param len Amount of characters to copy.
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * Duplicates a string to a new string.
 * @param *str String to be duplicated.
 * @return Returns a new string.
 */
char		*ft_strdup(const char *str);

#endif