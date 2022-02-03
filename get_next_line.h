/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/31 10:39:18 by buiterma      #+#    #+#                 */
/*   Updated: 2022/01/31 13:01:04 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

typedef struct s_data_store__gnl
{
	char	*readstr;
	char	*r_main;
}t_data_store_gnl;

//== get_next_line function ==/

char		*get_next_line(int fd);

//== util functions ==//

/**
 * Checks the length of the string.
 * @param *str The string to be checked
 * @return Returns the lenght of the string
 */
size_t		ft_strlen_gnl(char *str);

/**
 * Concatenates two string to one new string.
 * @param *s1 First string to concatenate.
 * @param *s2 Second string to concatenate.
 * @return Returns a new concatenated string.
 */
char		*ft_strappend_gnl(char *s1, char *s2);

/**
 * Searches for the first occurence of c in str.
 * If str is empty or c = '\0' it gives back a pointer
 * to the end of str.
 * @param *str The string to search through.
 * @param c The character to search for.
 * @return Returns a pointer to c in str.
 */
char		*ft_strchr_gnl(char *str, int c);

/**
 * Copies part of a string to a new string.
 * @param *s String to take from.
 * @param start Starting point where to copy from.
 * @param len Amount of characters to copy.
 */
char		*ft_substr_gnl(char *s, unsigned int start, size_t len);

/**
 * Duplicates a string to a new string.
 * @param *str String to be duplicated.
 * @return Returns a new string.
 */
char		*ft_strdup_gnl(char *str);

#endif