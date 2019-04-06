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
** Parse the line and return the arguments read from the input line.
*/

static char	**get_args(char *line)
{
	int		i;
	int		buffer;
	char	*token;
	char	**tokens;

	i = 0;
	buffer = TOK_BUFF;
	token = strtok(line, TOK_DELIM);
	tokens = (char **)malloc(sizeof(char *) * buffer);
	while (token)
	{
		tokens[i] = token;
		if (++i > buffer)
		{
			buffer += TOK_BUFF;
			tokens = (char **)realloc(tokens, buffer * sizeof(char *));
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}

/*
** Read a line from standard input or file.
*/

static char	*read_line(void)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	return (line);
}

/*
** Minishell
*/

int			minishell(char **env, char *name)
{
	int		status;
	char	*line;
	char	**args;

	status = 1;
	while (status)
	{
		write(1, PROMPT, strlen(PROMPT));
		line = read_line();
		args = get_args(line);
		status = run_cmd(args, env, name);
		free(line);
		free(args);
	}
	return (status);
}
