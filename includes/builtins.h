/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:22:32 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/25 10:22:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

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
** - strcmp()
** - strtok()
*/
# include <string.h>

/*
** - Local header files
*/
# include "utils.h"
# include "global.h"

/*
** Defined macros
*/
# define AUTHOR				("Jose Ramon Aleman")
# define BLTNS_NUM			(8)
# define BLTNS_CMDS(...)	__VA_ARGS__

/*
** Global vars
** - App name
** - Builtin list
** - Dispatch table func
*/
# ifndef GLOBAL_VAR
#  define GLOBAL_VAR

extern char		*g_builtin_str[];
extern int		(*g_builtin_func[])(char **);

# endif

/*
** Function prototypes
*/
int				builtins_get_total(void);
int				cmd_exit(char** args);
int				cmd_help(char** args);
int				cmd_env(char** args);
int				cmd_setenv(char** args);
int				cmd_cd(char** args);
int				cmd_echo(char** args);
int				cmd_baguette(char** args);
int				cmd_konami(char** args);

#endif
