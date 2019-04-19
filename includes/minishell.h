/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 17:01:52 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/14 17:01:56 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include <crt_externs.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "utils.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define YEL	"\x1B[33m"
# define RESET	"\x1B[0m"
# define BOLD	"\e[1m"
# define SPACES " \t\n\r\a\""
# define NOTEXIST "cd: no such file or directory: %s\n"
# define NOTDIR "cd: not a directory: %s\n"
# define NOPERM "cd: permission denied: %s\n"
# define NOPWD "cd: string not in pwd: %s\n"

# define BLT_NUM	(9)

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
