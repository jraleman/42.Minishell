/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:22:32 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/25 10:22:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Return the number of entries in a table
*/

static size_t	tablen(char **tab)
{
	int			len;

	len  = 0;
	while(tab[len] != NULL)
		len += 1;
	return (len);
}

/*
** Initialize a double pointer array to store the enviromental variables.
*/

static char		**init_env(char *envp[], char *path)
{
	char		**env;
	int			i;
	int			len;

	i = -1;
	len = tablen(envp);
	if (!(env = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (++i < len)
		env[i] = envp[i];
	env[i] = path;
	env[i + 1] = NULL;
	return (env);
}

/*
** Main function.
** Use third argument instead of -> extern char **environ;
*/

int			main(int argc, char *argv[], char *envp[], char *apple[])
{
	char	**env;

	env = init_env(envp, apple[0]);
	return (minishell(env, argv[0]));
	(void)argc;
}
