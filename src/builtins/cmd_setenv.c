/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:22:32 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/25 10:22:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cmd_putenv(char *entry, char **env)
{
	char	*tmp;
	char	**p;
	char	**new_env;
	size_t	len;
	size_t	size;

	tmp = strchr(entry, '=');
	len = (size_t)(tmp - entry + 1);
	for (p = env; *p; p += 1)
	{
		if (!strncmp(entry, *p, len))
		{
			*p = entry;
			return (1);
		}
	}
	size = p - env;
	new_env = (char **)malloc((sizeof(char *) * size + 2));
	memcpy((char *)new_env, (char *)env, (sizeof(char *)) * size);
	new_env[size] = entry;
	new_env[size + 1] = NULL;
	env = new_env;
	return (1);
}

int			cmd_setenv(char **args, char **env)
{
	char	*es;

	if (!args[1] || strchr(args[1], '=') || !args[2])
	{
		puts("Error");
		return (-1);
	}
	cmd_unsetenv(args, env, name);
	es = (char *)malloc(strlen(args[1]) + 1 + strlen(args[2]) + 1);
	strcpy(es, args[1]);
	strcat(es, "=");
	strcat(es, args[2]);
	return (cmd_putenv(es, env) != 1 ? -1 : 1);
}
