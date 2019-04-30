/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 17:01:52 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/14 17:01:56 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** Header files.
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/stat.h>
# include <sys/wait.h>

/*
** Local header files.
*/

# include "utils.h"

/*
** Macros.
*/

# define BLT_NUM		(9)
# define TOK_DELIM		" \t\n\r\a\""
# define CD_NOTEXIST	("No such file or directory.")
# define CD_NOTDIR		("Error opening directory.")
# define CD_NOPERM		("Permission denied.")

/*
** Main functions
*/

int		minishell(char **env, char *name);
char	**execute(char **args, char **env, char *name);
char	*blt_str(int i);
char	**(*blt_func(int i))(char **args, char **env, char *name);

/*
** Builtins
*/

char	**cmd_echo(char **args, char **env, char *name);
char	**cmd_cd(char **args, char **env, char *name);
char	**cmd_setenv(char **args, char **env, char *name);
char	**cmd_unsetenv(char **args, char **env, char *name);
char	**cmd_env(char **args, char **env, char *name);
char	**cmd_exit(char **args, char **env, char *name);
char	**cmd_pwd(char **args, char **env, char *name);
char	**cmd_help(char **args, char **env, char *name);
char	**cmd_squirtle(char **args, char **env, char *name);

#endif
