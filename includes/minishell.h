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

/*
** Header files
*/

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

#include "utils.h"
#include "builtins.h"

/*
** Defined macros
*/

# define ERR_MEM		        (-2)
# define BUFF_SIZE		      (64)
# define TOK_DELIM		      (" \t\r\n\a")
# define PRMPT_EMJ          (🍍)
# define PRMPT_BNS          (🐢)
# define CMD_PRMPT(icon)		(#icon "  > ")

/*
** Global vars
*/

# ifndef GLOBAL_VAR
#  define GLOBAL_VAR

static const char	*g_app;

# endif

/*
** Function prototypes
*/

int			cmd_exit(char **args);
int			cmd_help(char **args);
int			cmd_cd(char **args);
int			minishell(void);

#endif
