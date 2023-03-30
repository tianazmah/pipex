/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hnait <hnait@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/28 09:51:29 by hnait 	   		   #+#	#+#			 */
/*   Updated: 2023/03/14 17:38:58 by hnait			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_gnl_substr(char const *s, size_t len)
{
	char	*ss;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (len > ft_gnl_strlen(s))
		len = ft_gnl_strlen(s);
	ss = (char *) malloc (sizeof(char) * (len + 1));
	if (!ss)
		return (NULL);
	while (i < len && s[i])
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*ss;
	int		i;
	int		j;
	int		len_s1;
	int		len_s2;

	if (!s1)
		return (0);
	if (!s2)
		return (0);
	len_s1 = ft_gnl_strlen(s1);
	len_s2 = ft_gnl_strlen(s2);
	ss = (char *) ft_gnl_calloc (sizeof(char), (len_s1 + len_s2 + 1));
	if (!ss)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		ss[i] = s1[i];
	j = -1;
	while (++j < len_s2)
		ss[i + j] = s2[j];
	ss[i + j] = 0;
	ft_gnl_bzero(s2, BUFFER_SIZE);
	return (ss);
}

void	*ft_gnl_calloc(size_t count, size_t size)
{
	void	*tab;

	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	ft_gnl_bzero(tab, count * size);
	return (tab);
}

void	ft_gnl_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ss;

	ss = (char *) s;
	i = 0;
	while (i < n)
	{
		ss[i] = 0;
		i++;
	}
}
