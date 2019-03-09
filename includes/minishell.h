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
** Local header files
*/
# include "utils.h"
# include "builtins.h"

/*
** Defined macros
*/
# define BUFF_SIZE			(64)
# define TOK_DELIM			(" \t\r\n\a")
# define PRMPT_DFL			("🍍")
# define PRMPT_BNS			("🐢")
# define ICON_LINE			("☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️☁️")
# define ICON_ERRR			("💩")
# define NUM_PRMPT			(2)
# define CMD_PRMPT(PRMPT)	("%s  > "), (PRMPT)

/*
** ...
*/

typedef struct		s_sh
{
	int				div;
	wchar_t 		*prmpt;
	wchar_t			*icon;
	char			*builtin[NUM_BLTNS];
	int				*cmd[NUM_BLTNS](char **, char *);
}					t_sh;

/*
** Function prototypes
*/
int			minishell(char *bin, char *opt);

#endif
