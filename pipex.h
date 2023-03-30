/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:01:03 by hnait             #+#    #+#             */
/*   Updated: 2023/03/29 12:44:20 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"

char	**get_path(char **env);
char	*check_cmds(char *v, char **path);
void	second_command(char **v, char **path, int pip[2], char **envD);
void	first_command(char **v, char **path, int pip[2], char **envD);
int		get_fd(char *file_name);

#endif