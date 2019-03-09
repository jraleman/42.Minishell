#ifndef T_SH_H
# define T_SH_H

#include "builtins.h"

/*
** ...
*/

typedef struct		s_cmd
{
    const char		*name;
    int				(*fun)(char **, char *);
}					t_cmd;

/*
** ...
*/

typedef struct		s_opt
{
	int				div;
	wchar_t 		*prmpt;
	wchar_t			*icon;
}					t_opt;

/*
** ...
*/

typedef struct		s_sh
{
	t_opt			*opt;
	char			*builtin[NUM_BLTNS];
	// int				*cmd[NUM_BLTNS](char **, char *);
	t_cmd			*builtin_cmd;
}					t_sh;

/*
** Function prototypes.
*/

t_sh				*sh_init(char *bin, char *opt[], int count);

#endif
