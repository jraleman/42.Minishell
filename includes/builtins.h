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

# include <sys/wait.h>
    // waitpid() and associated macros
# include <unistd.h>
    // chdir()
    // fork()
    // exec()
    // pid_t
# include <stdlib.h>
    // malloc()
    // realloc()
    // free()
    // exit()
    // execvp()
    // EXIT_SUCCESS, EXIT_FAILURE
# include <stdio.h>
    // fprintf()
    // printf()
    // stderr
    // getchar()
    // perror()
# include <string.h>
    // strcmp()
    // strtok()

# include "global.h"

/*
** Macros
*/

# define AUTHOR			        ("Jose Ramon Aleman")
# define BLTNS_NUM          (8)
# define BLTNS_CMDS(...)    __VA_ARGS__

/*
** Function prototypes
*/

int		      builtins_get_total(void);
int         cmd_exit(char** args);
int         cmd_help(char** args);
int         cmd_env(char** args);
int         cmd_setenv(char** args);
int         cmd_cd(char** args);
int         cmd_echo(char** args);
int         cmd_baguette(char** args);
int         cmd_konami(char** args);

/*
** Builtin Structure
*/

static char *g_builtin_str[] =\
{
  BLTNS_CMDS("exit", "help", "env", "setenv", "cd", "echo"\
              , "baguette", "konami")
};
static int  (*g_builtin_func[])(char **) =\
{
  BLTNS_CMDS(&cmd_exit, &cmd_help, &cmd_env, &cmd_setenv, &cmd_cd, &cmd_echo\
              , &cmd_baguette, &cmd_konami)
};

#endif
