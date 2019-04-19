/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:08:34 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/17 17:08:36 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Print Minishell ascii art.
*/

static void	draw_ascii_art(void)
{
	ft_putchar('\n');
	ft_putendl(",-.-.o     o     |         |    |    ");
	ft_putendl("| | |.,---..,---.|---.,---.|    |    ");
	ft_putendl("| | |||   ||`---.|   ||---'|    |    ");
	ft_putendl("` ' '``   '``---'`   '`---'`---'`---'");
	return ;
}

/*
** Builtin help message command implementation.
*/

char		**cmd_help(char **args, char **env, char *name)
{
	int		i;

	i = -1;
	draw_ascii_art();
	ft_putendl("By: Jose Ramon Aleman\n\n");
	ft_putendl("Type program names and arguments, and hit enter.");
	ft_putendl("The following are built in:");
	while (++i < BLT_NUM)
		ft_putendl(blt_str(i));
	return (env);
	(void)args;
	(void)name;
}
