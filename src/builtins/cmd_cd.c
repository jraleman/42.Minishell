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
** Builtin cd command implementation.
*/

char		**cmd_cd(char **args, char **env)
{
	int		i;

	i = -1;
	if (!args[1] || (args[1][0] == '~' && !args[1][1]))
	{
		while (env[++i])
			if (!ft_strncmp(env[i], "HOME", 4))
				if (chdir(ft_strrchr(env[i], '=') + 1) == 0)
					break ;
	}
	else if (chdir(args[1]) != 0)
		write(2, "err\n", 4);
	return (env);
}
