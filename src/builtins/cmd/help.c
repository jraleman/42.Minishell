/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:22:32 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/25 10:22:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/*
** ...
*/

static void	print_info(void)
{
	printf("%s's Minishell\n", AUTHOR);
	printf("Type program names and arguments, and hit enter.\n");
	return ;
}

/*
** ...
*/

int			cmd_help(char **args)
{
	int		i;

	char	*tmp_bltns[BLTNS_NUM] = {"exit", "help", "env", "setenv", "cd", "echo", "baguette", "konami"};

	printf("%s\n", args[0]);
	i = -1;
	// (void)**args;
	print_info();
	printf("The following are built in:\n");
	while (++i < BLTNS_NUM)
		printf("    %s\n", tmp_bltns[i]);
	printf("Use the man command for information on other programs.\n");
	return (1);
}
