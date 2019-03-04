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

#include <sys/wait.h>
    // waitpid() and associated macros
#include <unistd.h>
    // chdir()
    // fork()
    // exec()
    // pid_t
#include <stdlib.h>
    // malloc()
    // realloc()
    // free()
    // exit()
    // execvp()
    // EXIT_SUCCESS, EXIT_FAILURE
#include <stdio.h>
    // fprintf()
    // printf()
    // stderr
    // getchar()
    // perror()
#include <string.h>
    // strcmp()
    // strtok()

/*
** Macros
*/

# define AUTHOR			    ("Jose Ramon Aleman")
# define BLTNS_CMD      (#a, #b, #c, #d, #e, #f, #g, #h") // ?
# define BLTNS_NAME(a, b, c, d, e, f, g, h) (BLTNS_CMD)

/*
** Builtin Structure
*/

char		*g_builtin_str[] =
{
  BLTNS_NAME("exit", "help", "env", "setenv", "cd", "echo", \
              "baguette", "konami")
};

int			(*builtin_func[])(char **) = NULL;
{
  BLTNS_NAME(&cmd_exit, &cmd_help, &cmd_env, &cmd_setenv, &cmd_cd, &cmd_echo,\
                &cmd_baguette, &cmd_konami)
}

#endif
