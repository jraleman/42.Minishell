/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_squirtle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:33:58 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/22 17:33:59 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Prints a squirtle.
*/

static void	draw_squirtle(void)
{
	ft_putendl("       _.-~~~~~~~-.                  ");
	ft_putendl("      /         _   ~.               ");
	ft_putendl("     |#`       /#`    \\             ");
	ft_putendl("     |-'|      |-'|    |             ");
	ft_putendl("     |-'|      |-'|    |             ");
	ft_putendl("     /--        --     |-.           ");
	ft_putendl("     \\__   .  .        / /\\_       ");
	ft_putendl("      \\ ~~--___---~~/\\| |   ~-.    ");
	ft_putendl("   .---`~~--____---_)  \\ \\-__  \\  ");
	ft_putendl("  ) <    |__    __\\_   \\ \\     |  ");
	ft_putendl("   ~-.__ /   ~~~~   \\   \\ \\     | ");
	ft_putendl("        ~-.   |     .~-.-' |    |    ");
	ft_putendl("         | \\___|___/     / /     |  ");
	ft_putendl("         | /   |   \\     | |  /  |  ");
	ft_putendl("          \\     |   ~-___ \\ \\/  / ");
	ft_putendl("          /\\__ / `._ /   ~-\\ \\_/  ");
	ft_putendl("         /    \\_____|      |`~      ");
	ft_putendl("        |      |    |      |         ");
	ft_putendl("         \\     |    |      |        ");
	ft_putendl("         >______)   /_/\\/\\_\\    \n");
	return ;
}

/*
** Prints the usage message.
*/

static void	print_usage(void)
{
	ft_putendl("Usage: squirtle \"your-message-here\"");
	return ;
}

/*
** Draw a dashed line.
*/

static void	dashed_line(int len)
{
	int		i;

	i = -1;
	ft_putchar(' ');
	while (++i < len + 2)
		ft_putchar('_');
	ft_putstr(" \n");
	return ;
}

/*
** Builtin cowsay like command implementation.
*/

char		**cmd_squirtle(char **args, char **env, char *name)
{
	int		line_size;

	if (!args[1] || args[2])
		print_usage();
	else
	{
		line_size = ft_strlen(args[1]);
		dashed_line(line_size);
		ft_putchar('\n');
		ft_putendl(args[1]);
		dashed_line(line_size);
		draw_squirtle();
	}
	return (env);
	(void)name;
}
