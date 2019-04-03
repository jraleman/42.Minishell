/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:22:32 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/25 10:22:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Execute arguments
*/

int			execute_args(char **args, char *prog_name)
{
	(void)args;
	(void)prog_name;
	return (0);
}

/*
** Parse the line and return the arguments read from the input line.
*/

char		**get_args(char *line)
{
	return ((char **)line);
}

/*
** Read a line from standard input or file.
*/

char		*read_line(void)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	return (line);
}

/*
** Minishell
*/

int			minishell(char *prog_name)
{
	int		status;
	char	*line;
	char	**args;

	status = 1;
	while (status)
	{
		printf("%s\n", "> ");
		line = read_line();
		printf("%s\n", line);
		args = get_args(line);
		status = execute_args(args, prog_name);
		free(line);
		free(args);
	}
	return (status);
}
