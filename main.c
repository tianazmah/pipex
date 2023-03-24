#include "pipex.h"

int main(int c, char** v, char **env)
{
	char	**path;

	if (c != 5)
		return (0);
	v++;
	path = get_path(env);
	check_cmds(v, path);
	while (1);
	
}

char	**get_path(char **env)
{
	int	i;
	char **path;
	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	path = ft_split(ft_strtrim(env[i], "PATH="), ':');
	return (path);
}

void	check_cmds(char **v, char **path)
{
	char	*conatcmd1;
	char	*cmd1;
	char	*conatcmd2;
	char	*cmd2;
	int		i;

	cmd1 = NULL;
	cmd2 = NULL;
	i = 0;
	while (path[i])
	{
		conatcmd1 = ft_strdup(path[i]);
		ft_strlcat(conatcmd1, "/", ft_strlen(conatcmd1) + 2);
		ft_strlcat(conatcmd1, v[1], ft_strlen(conatcmd1) + ft_strlen(v[1]) + 1);
		ft_printf("concatcmd1 %s\n", conatcmd1);
		if (!access(conatcmd1, X_OK))
			cmd1 = conatcmd1;
		else
			free(conatcmd1);
		
		conatcmd2 = ft_strdup(path[i]);
		ft_strlcat(conatcmd2, "/", ft_strlen(conatcmd2) + 2);
		ft_strlcat(conatcmd2, v[2], ft_strlen(conatcmd2) + ft_strlen(v[2]) + 1);
		ft_printf("concatcmd2 %s\n", conatcmd2);
		if (!access(conatcmd2, X_OK))
			cmd2 = conatcmd2;
		else
			free(conatcmd2);
		i++;
	}
	ft_printf("cmd1 :%s\n cmd2 :%s", cmd1, cmd2);
}