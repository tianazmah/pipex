/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:59:08 by hnait             #+#    #+#             */
/*   Updated: 2023/03/30 21:04:33 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int c, char **v, char **env)
{
	char	**path;
	int		id;
	int		pip[2];
	char	*ex_env[1];

	*ex_env = NULL;
	pipe(pip);
	if (c != 5)
		return (0);
	if (!env)
		return (0);
	path = get_path(env);
	id = fork();
	if (id == 0)
		first_command(v, path, pip, ex_env);
	else
	{
		wait(NULL);
		second_command(v, path, pip, ex_env);
	}
}

void	first_command(char **v, char **path, int pip[2], char **ex_env)
{
	char	*cmd;
	char	*holder;
	char	*all_command;
	char	**mycmd;

	close(pip[0]);
	cmd = check_cmds(v[2], path);
	holder = ft_strjoin(v[2], " ");
	all_command = ft_strjoin(holder, v[1]);
	mycmd = ft_split(all_command, ' ');
	dup2(pip[1], 1);
	close(pip[1]);
	free(holder);
	free(all_command);
	execve(cmd, mycmd, ex_env);
}

void	second_command(char **v, char **path, int pip[2], char **ex_env)
{
	char	*cmd;
	char	*holder;
	char	*all_command;
	char	**mycmd;
	int		input_fd;

	close(pip[1]);
	cmd = check_cmds(v[3], path);
	mycmd = ft_split(v[3], ' ');
	input_fd = get_fd(v[4]);
	dup2(pip[0], 0);
	dup2(input_fd, 1);
	close(pip[0]);
	free(all_command);
	execve(cmd, mycmd, ex_env);
}

int	get_fd(char *file_name)
{
	int	fd;

	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
		{
			ft_printf("hhhhhhh\n");
			exit(1);}
	return (fd);
}

char	**get_path(char **env)
{
	int		i;
	char	**path;
	char	*trimed_path;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	trimed_path = ft_strtrim(env[i], "PATH=");
	path = ft_split(trimed_path, ':');
	free(trimed_path);
	return (path);
}

char	*empty_command(char *command)
{
	char	*trimed_command;

	if (!*command)
	{
		ft_printf("permission denied:\n");
		exit(0);
	}
	trimed_command = ft_strtrim(command, " ");
	if (ft_strlen(trimed_command) == 0)
	{
		ft_printf("commade no found:\n");
		exit(0);
	}
	return (trimed_command);
}

char	**functio(char **path, char *trimed_command, int i, int *read)
{
	char	*holder;
	char	*concat;
	char	**test_access;
	char	*cmd;

	holder = ft_strjoin(path[i], "/");
	concat = ft_strjoin(holder, trimed_command);
	test_access = ft_split(concat, ' ');
	if (!access(*test_access, R_OK))
	{
		*read = 1;
		if (!access(*test_access, X_OK))
			return (free(holder), free(concat),
				free(trimed_command), test_access);
	}
	free_ss(test_access);
	free(test_access);
	free(concat);
	free(holder);
	return (NULL);
}

char	*check_cmds(char *command, char **path)
{
	int		i;
	int		read;
	char	**test_access;
	char	*trimed_command;

	i = 0;
	read = 0;
	trimed_command = empty_command(command);
	while (path[i])
	{
		test_access = functio(path, trimed_command, i, &read);
		if (test_access != NULL)
			return (*test_access);
		i++;
	}
	if (read == 1)
		ft_printf("permission denied: %s\n", trimed_command);
	else
		ft_printf("command not found: %s\n", trimed_command);
	return (free_ss(path), free(path), free(trimed_command), exit(0), NULL);
}
