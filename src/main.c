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
** Print usage message.
*/

static void	print_usage()
{
	printf("usage: %s\n", g_app);
	return ;
}

/*
** Main program function
*/

int			main(int argc, char *argv[])
{
	int		ret;

	ret = EXIT_OK;
	g_app = argv[0];
	if (argc == 1)
		ret = minishell();
	else
		print_usage();
	return (ret);
}
