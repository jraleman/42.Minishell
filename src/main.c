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

static int		print_usage(char *bin)
{
	printf("usage: %s [option]\n", bin);
	return (EXIT_FAILURE);
}

/*
** Set invalid flag.
*/

static int		invalid_flag(char *bin, char opt)
{
	printf("%s: illegal option -- %c\n", bin, opt);
	return (0);
}

/*
** Validate flag.
*/

static int		validate_flag(char *bin, char *flag)
{
	int			i;
	int			ret;

	i = 0;
	ret = 1;
	while (ret == 1 && flag[++i])
		if (!ft_cisin(OPTS_FLGS, flag[i]))
			ret = invalid_flag(bin, flag[i]);
	return (ret);
}

/*
** Verify flags.
*/

static int		verify_flags(char *bin, char *flags[], int total)
{
	int			i;

	i = 0;
	while (++i < total)
	{
		if (flags[i][0] == '-' && validate_flag(bin, flags[i]))
			continue ;
		break ;
	}
	return (i == total);
}

/*
** Main function.
*/

int			main(int argc, char *argv[])
{
	int		ret;
	int		valid;

	ret = EXIT_SUCCESS;
	valid = verify_flags(argv[0], argv, argc);
	if (argc == 1)
		ret = minishell(argv[0], NULL);
	else if (valid && argc > 1)
		ret = minishell(argv[0], argv);
	else
		ret = print_usage(argv[0]);
	return (ret);
}
