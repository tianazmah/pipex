/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:45:51 by hnait             #+#    #+#             */
/*   Updated: 2023/04/05 13:46:25 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_command_line(char *cmd, char *file_name)
{
	char	**command_line;

	cmd = ft_strjoin(cmd, " ", 0);
	if (file_name)
		cmd = ft_strjoin(cmd, file_name, 1);
	command_line = ft_split(cmd, ' ');
	free(cmd);
	return (command_line);
}

char	*get_command(char *cmd, char **env)
{
	char	*command;
	char	**path;
	char	**split_command;
	char	*valid_command;

	path = get_path(env);
	command = ft_strtrim(cmd, " ");
	split_command = ft_split(command, ' ');
	free(command);
	command = ft_strdup(split_command[0]);
	free_ss(split_command);
	free(split_command);
	valid_command = check_command(command, path);
	free_ss(path);
	free(path);
	free(command);
	if (valid_command)
		return (valid_command);
	else
		exit(1);
	return (0);
}

char	*check_command(char *command, char **path)
{
	int		i;
	char	*valid_command;
	char	*tmp;

	i = 0;
	if (access(command, X_OK) == 0)
		return (ft_strdup(command));
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/", 0);
		valid_command = ft_strjoin(tmp, command, 1);
		if (access(valid_command, X_OK) == 0)
			return (valid_command);
		i++;
		free(valid_command);
	}
	dup2(2, 1);
	ft_printf("Error: Command not found: %s\n", command);
	return (0);
}

char	**get_path(char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(env[i] + 5, ':');
			return (path);
		}
		i++;
	}
	return (0);
}
