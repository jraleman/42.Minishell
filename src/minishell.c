/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 16:53:58 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/14 16:53:59 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Read a line from standard input or file.
*/

static char	*read_line(void)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	return (line);
}

/*
** ...
*/

static char	**run_cmd(char **comands, char **env, char *name)
{
	char	**args;
	int		i;
	int		j;

	(void)name;

	i = 0;
	j = 0;
	while (comands[j])
	{
		args = ft_strtok(comands[j], SPACES);
		env = execute(args, env);
		free(comands[j]);
		j += 1;
		while (args[i])
			free(args[i++]);
		(args) ? free(args) : 0;
		if (!env)
			return (NULL);
	}
	return (env);
}

/*
** ...
*/

static void	set_dir(char **env, char *dirname)
{
	char **a;

	a = (char**)ft_memalloc(sizeof(char*) * 4);
	a[0] = NULL;
	a[1] = ft_strdup(dirname);
	a[2] = ft_strnew(PATH_MAX);
	getcwd(a[2], PATH_MAX);
	a[3] = 0;
	cmd_setenv(a, env);
	free(a[1]);
	free(a[2]);
	free(a);
}

int			minishell(char **env, char *name)
{
	int 	status;
	char	*line;
	char	**comands;

	status = 1;
	while (status)
	{
		write(1, "> ", 2);
		set_dir(env, "PWD");
		line = read_line();
		comands = ft_strtok(line, ";");
		env = run_cmd(comands, env, name);
		status = env ? 1 : 0;
		free(comands);
		free(line);
	}
	return (status);
}
