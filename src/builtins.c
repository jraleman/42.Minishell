/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:08:34 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/17 17:08:36 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Builtin commands names.
*/

char		*blt_str(int i)
{
	char	*blt_str[BLT_NUM + 1];

	blt_str[0] = "cd";
	blt_str[1] = "echo";
	blt_str[2] = "exit";
	blt_str[3] = "env";
	blt_str[4] = "setenv";
	blt_str[5] = "unsetenv";
	blt_str[6] = "help";
	blt_str[7] = "pwd";
	blt_str[8] = "squirtle";
	blt_str[9] = NULL;
	return (blt_str[i]);
}

/*
** Builtin commands functions.
*/

char		**(*blt_func(int i))(char **args, char **env, char *name)
{
	char	**(*blt_func[BLT_NUM])(char **args, char **env, char *name);

	blt_func[0] = &cmd_cd;
	blt_func[1] = &cmd_echo;
	blt_func[2] = &cmd_exit;
	blt_func[3] = &cmd_env;
	blt_func[4] = &cmd_setenv;
	blt_func[5] = &cmd_unsetenv;
	blt_func[6] = &cmd_help;
	blt_func[7] = &cmd_pwd;
	blt_func[8] = &cmd_squirtle;
	return (blt_func[i]);
}
