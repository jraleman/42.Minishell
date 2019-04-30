/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:22:32 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/25 10:22:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Returns the count of arguments passed as parameter.
*/

static int		count_args(char **args)
{
	int			count;

	count = 0;
	while (args[count])
		count += 1;
	return (count);
}

/*
** Set the path working directory.
*/

static void		set_dir(char **env, char *name)
{
	char	**arg;

	arg = (char **)ft_memalloc(sizeof(char *) * 4);
	arg[0] = NULL;
	arg[1] = ft_strdup("PWD");
	arg[2] = ft_strnew(PATH_MAX);
	arg[3] = 0;
	getcwd(arg[2], PATH_MAX);
	cmd_setenv(arg, env, name);
	free(arg[1]);
	free(arg[2]);
	free(arg);
	return ;
}

/*
** Access a directory, else prints an error message defined by a macro.
*/

static void		access_dir(char **env, char *path)
{
	char		*msg;
	struct stat	stt;

	msg = NULL;
	if (!(access(path, F_OK) == -1))
		lstat(path, &stt);
	else
		msg = CD_NOTEXIST;
	if (!(access(path, R_OK) != -1))
		msg = CD_NOPERM;
	if (!S_ISDIR(stt.st_mode))
		msg = CD_NOTDIR;
	if (msg)
		ft_putendl(msg);
	else
	{
		set_dir(env, "OLDPWD");
		chdir(path);
	}
	return ;
}

/*
** Builtin cd command implementation.
*/

char			**cmd_cd(char **a, char **env, char *name)
{
	int			i;
	char		p[PATH_MAX + 1];

	i = -1;
	while (++i < PATH_MAX)
		p[i] = 0;
	if (count_args(a) < 3)
	{
		(a)++;
		if (!*a || !ft_strcmp(*a, "~") \
			|| ((*a)[0] == '~' && (*a)[1] == '/'))
			ft_strcat(p, ft_find_env("~", env));
		if (*a && (*a)[0] == '~' && (*a)[1] == '/' \
			&& ft_strlen(*a) > 2)
			ft_strncat(p, (*a + 1), ft_strlen(*a));
		else if (*a && !ft_strcmp(*a, "-"))
			ft_putendl(ft_strcat(p, ft_find_env("$OLDPWD", env)));
		else if (*a && (*a)[0] != '~' && (*a)[0] != '-')
			ft_strncat(p, *a, PATH_MAX);
		access_dir(env, p);
	}
	return (env);
	(void)name;
}
