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
** Execute a process
*/

static int	execute_ps(char **args, char *name)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	status = 0;
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			printf("%s\n", name);
		exit(1);
	}
	else if (pid < 0)
		printf("%s\n", "error");
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

/*
** Builtin commands name
*/

static char	*blt_str(int i)
{
	char	*blt_str[BLT_NUM];

	blt_str[0] = "cd";
	blt_str[1] = "echo";
	blt_str[2] = "exit";
	blt_str[3] = "env";
	blt_str[4] = "setenv";
	blt_str[5] = "unsetenv";
	return (blt_str[i]);
}

/*
** Builtin commands function
*/

static int	(*blt_func(int i))(char **args, char **env, char *name)
{
	int		(*blt_func[BLT_NUM])(char **args, char **env, char *name);

	blt_func[0] = &cmd_cd;
	blt_func[1] = &cmd_echo;
	blt_func[2] = &cmd_exit;
	blt_func[3] = &cmd_env;
	blt_func[4] = &cmd_setenv;
	blt_func[5] = &cmd_unsetenv;
	return (blt_func[i]);
}

/*
** Run a command
*/

int			run_cmd(char **args, char **env, char *name)
{
	int		i;

	i = -1;
	if (args[0] == NULL)
		return (1);
	while (++i < BLT_NUM)
		if (strcmp(args[0], blt_str(i)) == 0)
			return ((*blt_func(i))(args, env, name));
	return (execute_ps(args, name));
}
