/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:10:30 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/22 19:10:31 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Builtin pwd command implementation.
*/

char	**cmd_pwd(char **args, char **env, char *name)
{
	char	buf[PATH_MAX + 1];
	int		i;

	i = 0;
	while (args[i])
		i += 1;
	if (i > 1)
	{
		ft_putstr(args[0]);
		ft_putendl(": too many arguments");
	}
	else if (i == 1)
		ft_putendl(getcwd(buf, PATH_MAX));
	return (env);
	(void)name;
}
