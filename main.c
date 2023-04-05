/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:59:08 by hnait             #+#    #+#             */
/*   Updated: 2023/04/04 22:42:57 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **arg_env)
{
	char	**command_line;
	char	*cmd;
	int		fd[2];
	char	*env[1];
	int		id;

	*env = NULL;
	pipe(fd);
	check_argc_argv(argc, argv);
	id = fork();
	if (id == 0)
	{
		cmd = get_command(argv[2], arg_env);
		command_line = get_command_line(argv[2], argv[1]);
		set_fd(fd, id);
	}
	else
	{
		wait(NULL);
		cmd = get_command(argv[3], arg_env);
		command_line = get_command_line(argv[3], NULL);
		set_fd(fd, id);
	}
	// system("leaks pipex");
	execve(cmd, command_line, env);
}

void	set_fd(int fd[2], int id)
{
	int	fd_file;

	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		fd_file = open("file", O_RDWR | O_CREAT | O_TRUNC, 0777);
		dup2(fd_file, 1);
	}
}

void	check_argc_argv(int argc, char **argv)
{
	char	*trimed_command1;
	char	*trimed_command2;

	if(argc != 5)
	{
		dup2(2, 1);
		ft_printf("Error: Wrong number of arguments\n");
		exit(1);
	}
	if (!*argv[2] || !*argv[3])
	{
		dup2(2, 1);
		ft_printf("Error: Permissin denied\n");
		exit(1);
	}
	trimed_command1 = ft_strtrim(argv[2], " ");
	trimed_command2 = ft_strtrim(argv[3], " ");
	if (!*trimed_command1 || !*trimed_command2)
	{
		dup2(2, 1);
		ft_printf("Error: Command not found\n");
		exit(1);
	}
}

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
	char 	**split_command;
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
	{
		perror("Error");
		exit(1);
	}
	return (0);
}

char	*check_command(char *command, char **path)
{
	int		i;
	char	*valid_command;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/", 0);
		valid_command = ft_strjoin(tmp, command, 1);
		if (access(valid_command, F_OK) == 0)
			return (valid_command);
		i++;
		free(valid_command);
	}
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
