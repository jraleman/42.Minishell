#include "minishell.h"

char	**cmd_env(char **args, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		write(1, env[i], ft_strlen(env[i]));
		write(1, "\n", 1);
		i += 1;
	}
		// ft_printf("%s\n", env[i++]);
	return (env);
	(void)args;
}
