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

static void	print_usage(char *app_name)
{
	printf("usage: %s [option]\n", app_name);
	return ;
}

/*
** Main program function
*/

int			main(int argc, char *argv[])
{
	int		ret;

	ret = EXIT_SUCCESS;
	g_app = argv[0];
	if (argc == 1)
		ret = minishell(NULL);
		// ret = minishell(argv[0], NULL);
	else if (argc == 2)
		ret = minishell(argv[1]);
		// ret = minishell(argv[0], argv[1]);
	else
		print_usage(argv[0]);
	return (ret);
}
