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

static int	print_usage(char *bin)
{
	printf("usage: %s [option]\n", bin);
	return (EXIT_SUCCESS);
}

/*
** Main program function
*/

int			main(int argc, char *argv[])
{
	int		ret;
	char	*bin;
	char	*opt;

	ret = EXIT_SUCCESS;
	bin = argv[0];
	opt = argv[1];
	if (argc == 1)
		ret = minishell(bin, NULL);
	else if (argc == 2)
		ret = minishell(bin, opt);
	else
		ret = print_usage(bin);
	return (ret);
}
