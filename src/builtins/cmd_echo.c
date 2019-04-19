/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:08:34 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/17 17:08:36 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_env(char *args, int k, char **env)
{
	char *s;

	(ft_find_env(args, env)[0] != 0) ? s = ft_find_env(args, env) : 0;
	if (ft_find_env(args, env)[0] == 0)
		return (-1);
	// ft_printf("%s", s);
	write(1, s, ft_strlen(s));
	while (args[k])
		k++;
	return (k);
}

static int	check_arg(char **s, int j, char **env)
{
	int			k;

	k = 0;
	while (s[j][k])
	{
		if (s[j][k] == '"' || s[j][k] == '\'' || s[j][k] == '\\')
			k++;
		if (!s[j][k])
			break ;
		if ((s[j][k] == '$' || s[j][k] == '~') &&
			(k = check_env(s[j], k, env)) == -1)
			return (-1);
		else
			(s[j][k] ? write(1, &s[j][k], 1) : 0);
		k++;
	}
	return (0);
}

int			read_args(char **args, int j, char **env)
{
	while (args[j])
	{
		if (check_arg(args, j, env) == -1)
			return (-1);
		(args[++j]) ? write(1, " ", 1) : 0;
	}
	return (0);
}

int			check_str(char **args, int j, char **env)
{
	char *s;

	s = NULL;
	if (args[j][0])
	{
		if (read_args(args, j, env) == -1)
			return (-1);
	}
	return (0);
}

char		**cmd_echo(char **a, char **env)
{
	int		i;
	int		j;
	int		new_line;

	i = 1;
	j = 0;
	if (!a[1] || !a[1][0])
	{
		// ft_printf("\n");
		write(1, "\n", 1);
		return (env);
	}
	new_line = (!ft_strncmp("-n", a[++j], PATH_MAX)) ? 1 : 0;
	(new_line) ? j++ : 0;
	check_str(a, j, env);
	// (new_line) ? 0 : ft_printf("\n");
	new_line ? 0 : write(1, "\n", 1);
	return (env);
}
