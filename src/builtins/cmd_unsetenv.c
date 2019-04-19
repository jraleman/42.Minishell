/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:41:33 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/19 16:41:35 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Builtin unsetenv command implementation.
*/

char	**cmd_unsetenv(char **args, char **env, char *name)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(args[1]);
	(args[1]) ? (args[1] += (args[1][0] == '$')) : 0;
	if (!ft_strcmp(args[1], "PWD"))
		ft_putendl("I can't let you do that...");
	else if (args[1] && ft_find_env(args[1], env)[0] != 0)
	{
		while (env[++i])
			if (!ft_strncmp(env[i], args[1], len) && env[i][len] == '=')
				break ;
		free(env[i]);
		i -= 1;
		while (env[++i])
			env[i] = env[i + 1];
		env[i] = NULL;
	}
	return (env);
	(void)name;
}
