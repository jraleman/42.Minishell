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

# include "utils.h"
# include "builtins.h"
# include "global.h"

/*
** Defined macros
*/

# define BUFF_SIZE		      (64)
# define TOK_DELIM		      (" \t\r\n\a")
# define PRMPT_DFL          ("🍍")
# define PRMPT_BNS          ("🐢")
# define NUM_ICONS          (2)
# define CMD_PRMPT(icon)		("%s  > "), #icon

/*
** Function prototypes
*/

int			minishell(void);

#endif
