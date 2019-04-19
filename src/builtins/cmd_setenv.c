/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:17:09 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/18 23:17:11 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** ...
*/

static char	**replace(char **args, char **env)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(args[1]);
	while (env[++i])
	{
		if (!ft_strncmp(env[i], args[1], len) && env[i][len] == '=')
			break ;
	}
	ft_strclr(env[i]);
	ft_strcat(env[i], args[1]);
	ft_strcat(env[i], "=");
	ft_strcat(env[i], args[2]);
	return (env);
}

/*
** ...
*/

static char	**create_new(char **args, char **env)
{
	char	***e;
	char	**envp;
	int		i;

	i = -1;
	e = &env;
	while ((*e)[++i])
		NULL;
	envp = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	i = -1;
	while ((*e)[++i])
		envp[i] = ft_strdup((*e)[i]);
	ft_tabfree(env);
	envp[i] = (char*)ft_memalloc(PATH_MAX + 1);
	ft_strncat(envp[i], args[1], ft_strlen(args[1]));
	ft_strncat(envp[i], "=", 1);
	ft_strncat(envp[i], args[2], ft_strlen(args[2]));
	e = &envp;
	return (*e);
}

/*
** ...
*/

static void	free_ar(char **a)
{
	free(a[1]);
	free(a[2]);
	free(a);
}

/*
** ...
*/

static char	**one_arg(char **args, char **env)
{
	int		i;
	int		j;
	char	**a;

	i = (args[1][0] == '"');
	j = 0;
	a = (char**)ft_memalloc(sizeof(char*) * 3);
	a[0] = NULL;
	a[1] = ft_strnew(sizeof(args[1]));
	a[2] = ft_strnew(sizeof(args[1]));
	while (args[1][i] != '=' && args[1][i])
		a[1][j++] = args[1][i++];
	if (!args[1][i])
	{
		free(a);
		return (env);
	}
	j = 0;
	while (args[1][++i] != '"' && args[1][i])
		a[2][j++] = args[1][i];
	env = cmd_setenv(a, env);
	free_ar(a);
	return (env);
}

/*
** ...
*/

char		**cmd_setenv(char **args, char **env)
{
	if (!args[1])
		return (env);
	if (!args[2])
		return (one_arg(args, env));
	if (ft_find_env(args[1], env)[0] != 0)
		return (replace(args, env));
	return (create_new(args, env));
}
