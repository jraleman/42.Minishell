/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:22:32 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/25 10:22:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Builtin commands name
*/

static char	*blt_str(int i)
{
	char	*blt_str[BLT_NUM + 1];

	blt_str[0] = "cd";
	blt_str[1] = "echo";
	blt_str[2] = "exit";
	blt_str[3] = "env";
	blt_str[4] = "setenv";
	blt_str[5] = "unsetenv";
	blt_str[6] = NULL;
	return (blt_str[i]);
}

/*
** Builtin commands function
*/

static int	(*blt_func(int i))(char **args, char **env)
{
	int		(*blt_func[BLT_NUM])(char **args, char **env);

	blt_func[0] = &cmd_cd;
	blt_func[1] = &cmd_echo;
	blt_func[2] = &cmd_exit;
	blt_func[3] = &cmd_env;
	blt_func[4] = &cmd_setenv;
	blt_func[5] = &cmd_unsetenv;
	return (blt_func[i]);
}

/*
** Execute a process
*/

static int	execute_ps(char **args, char **env, char *name)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(args[0], args, env) == -1 \
			? ft_error(1, name, "permission denied") : 0;
	else if (pid < 0)
		ft_error(1, name, "failed to fork");
	else
		wait(&pid);
	return (1);
}

/*
** Run a command
*/

int			run_cmd(char **args, char **env, char *name)
{
	int		i;
	char	*tmp;

	i = -1;
	if (args[0] == NULL)
		return (1);
	while (++i < BLT_NUM)
		if (strcmp(args[0], blt_str(i)) == 0)
			return ((*blt_func(i))(args, env));
	tmp = strdup("/bin/");
	strcat(tmp, args[0]);
	strncpy(args[0], tmp, strlen(tmp));
	free(tmp);
	return (execute_ps(args, env, name));
}
