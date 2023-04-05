/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:45:56 by hnait             #+#    #+#             */
/*   Updated: 2023/04/05 13:54:39 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_argc_argv(int argc, char **argv)
{
	char	*trimed_command1;
	char	*trimed_command2;

	if (argc != 5)
		prompt_error("Wrong number of arguments");
	if (!*argv[2] || !*argv[3])
		prompt_error("Permissin denied");
	trimed_command1 = ft_strtrim(argv[2], " ");
	trimed_command2 = ft_strtrim(argv[3], " ");
	if (!*trimed_command1 || !*trimed_command2)
		prompt_error("Command not found: ");
}
