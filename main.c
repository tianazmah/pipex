/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:59:08 by hnait             #+#    #+#             */
/*   Updated: 2023/04/05 13:54:14 by hnait            ###   ########.fr       */
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
	check_argc_argv(argc, argv);
	if (pipe(fd))
		prompt_error("Pipe failed");
	id = fork_and_get_id();
	if (id == 0)
	{
		cmd = get_command(argv[2], arg_env);
		command_line = get_command_line(argv[2], argv[1]);
		set_fd(fd, id, argv[4]);
	}
	else
	{
		wait(NULL);
		cmd = get_command(argv[3], arg_env);
		command_line = get_command_line(argv[3], NULL);
		set_fd(fd, id, argv[4]);
	}
	execve(cmd, command_line, env);
}

int	fork_and_get_id(void)
{
	int	id;

	id = fork();
	if (id < 0)
		prompt_error("Fork failed");
	return (id);
}

void	set_fd(int fd[2], int id, char *file_name)
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
		fd_file = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (fd_file < 0)
			prompt_error("File not found");
		dup2(fd_file, 1);
	}
}

void	prompt_error(char *error)
{
	dup2(2, 1);
	ft_printf("Error: %s\n", error);
	exit(1);
}
