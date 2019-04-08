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
** Prints a welcome message
*/

static void		print_welcome(char *path, char *name)
{
	printf("%s\n", path);
	printf("%s\n", name);
	return ;
}

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
** Main function.
** Use third argument instead of -> extern char **environ;
*/

int			main(int argc, char *argv[], char *envp[], char *apple[])
{
	char	**env;

	print_welcome(apple[0], argv[0]);
	return (minishell(env, argv[0]));
	(void)argc;
}
