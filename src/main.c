/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 16:53:58 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/14 16:53:59 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Init enviromental variables table.
*/

static void	init_env(char ***env, char **envp)
{
	int		i;
	int		j;

	i = -1;
	while (envp[++i])
		NULL;
	(*env) = (char **)ft_memalloc(sizeof(char*) * i);
	i = -1;
	while (envp[++i])
	{
		(*env)[i] = (char *)ft_memalloc(PATH_MAX + 1);
		j = -1;
		while (envp[i][++j])
			(*env)[i][j] = envp[i][j];
		(*env)[i][j] = 0;
	}
	(*env)[i] = NULL;
	i = -1;
	return ;
}

/*
** Main function.
*/

int			main(int argc, char *argv[], char *envp[], char *apple[])
{
	char	**env;

	init_env(&env, envp);
	return (minishell(env, argv[0]));
	(void)argc;
	(void)apple;
}
