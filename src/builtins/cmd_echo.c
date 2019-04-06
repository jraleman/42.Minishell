/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:22:32 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/25 10:22:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_eval(char **env, char *arg)
{
	char	*eval;

	eval = "Eval";
	return (eval);
	(void)env;
	(void)arg;
}

char		*echo_arg(char **env, char *arg, int last)
{
	char	*str;

	str = ((arg && arg[0] == '$') ? get_eval(env, arg) : arg);
	write(1, str, strlen(str));
	write(1, (!last ? " \n" : "\n"), (!last ? 2 : 1));
	return (str);
}

int			cmd_echo(char **args, char **env, char *name)
{
	int		i;

	i = 0;
	if (*args && args[1])
		while (args[++i])
			echo_arg(env, args[i], (args[i + 1] ? 1 : 0));
	return (1);
	(void)name;
}
