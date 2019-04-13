/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:22:32 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/25 10:22:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "utils.h"

/*
** - waitpid()
** - associated macros
*/
# include <sys/wait.h>

/*
** - chdir()
** - fork()
** - exec()
** - pid_t
*/
# include <unistd.h>

/*
** - malloc()
** - realloc()
** - free()
** - exit()
** - execvp()
** - EXIT_SUCCESS, EXIT_FAILURE
*/
# include <stdlib.h>

/*
** - fprintf()
** - printf()
** - stderr
** - getchar()
** - perror()
*/
# include <stdio.h>

/*
** strcmp()
** strtok()
*/
# include <string.h>

/*
** Macros
*/

# define BLT_NUM	(6)
# define TOK_DELIM	(" \t\r\n\a")
# define TOK_BUFF	(8)
# define PROMPT		(">  ")

/*
** Prototypes
*/

int				minishell(char **env, char *name);
int				run_cmd(char **args, char **env, char *name);
int				cmd_exit(char **args, char **env);
int				cmd_echo(char **args, char **env);
int				cmd_cd(char **args, char **env);
int				cmd_env(char **args, char **env);
int				cmd_setenv(char **args, char **env);
int				cmd_unsetenv(char **args, char **env);

#endif
