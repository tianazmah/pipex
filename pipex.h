/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:01:03 by hnait             #+#    #+#             */
/*   Updated: 2023/04/05 13:54:57 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"

char	*get_command(char *cmd, char **env);
char	*check_command(char *command, char **path);
char	**get_path(char **env);
char	**get_command_line(char *cmd, char *file_name);
void	check_argc_argv(int argc, char **argv);
void	set_fd(int fd[2], int id, char *file_name);
void	prompt_error(char *error);
int		fork_and_get_id(void);

#endif