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

// #include "minishell.h"

/*
** Shell looping function
*/

int			sh_loop(char *argv[])
{
	int		ret;
	int		loop;
	char	*line;
	char	**args;

	ret = 0;
	loop = 1;
	while (loop)
	{
		printf("🍍 ");

		free(line);
		free(args);
	}
	return (ret);
}

// -----------------------------------------------------------------------------


/*
** Main program function
*/

int			main(int argc, char *argv[])
{
	int		ret;

	ret = 0;
	if (argc == 1)
		ret = sh_loop(NULL);
	else if (argc == 2)
		ret = sh_loop(argv[1]);
	return (ret);
}
