/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.h									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hnait <hnait@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/01 18:25:34 by hnait 	   		   #+#	#+#			 */
/*   Updated: 2023/03/14 17:38:58 by hnait			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		find_nl_index(char **next_line, char *buffer);
void	remove_nl(char *next_line, int nl_index);
int		find_nl(char **next_line, int fd);
void	ft_gnl_bzero(void *s, size_t n);
void	*ft_gnl_calloc(size_t count, size_t size);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_substr(char const *s, size_t len);
size_t	ft_gnl_strlen(const char *s);

#endif