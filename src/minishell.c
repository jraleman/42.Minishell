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
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	status = 0;
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			printf("%s\n", prog_name);
		}
		exit(1);
	}
	else if (pid < 0)
	  printf("%s\n", "error");
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

/*
** Parse the line and return the arguments read from the input line.
*/

# define TOK_DELIM		(" \t\r\n\a")
# define TOK_BUFF		(8)

char		**get_args(char *line)
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

char		*read_line(void)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	return (line);
}

# define PROMPT		("🍍")

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
		// printf("%s", PROMPT);
		// ft_putwchar(PROMPT);
		write(1, ">  ", 3);
		line = read_line();
		args = get_args(line);
		// printf("%s\n", args[1]);
		status = execute_args(args, prog_name);
		free(line);
		free(args);
	}
	return (status);
}
