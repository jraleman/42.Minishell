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
#include <stdio.h>
#include <stdlib.h>

/*
** Macros
*/

# define EXIT_OK		(0)
# define EXIT_FAIL		(1)
# define ERR_MEM		(2)
# define BUFF_SIZE		(64)
# define TOK_DELIM		(" \t\r\n\a")

/*
** Globals
*/

char	*g_app = NULL;

// -----------------------------------------------------------------------------

void		ft_error(char *bin, int err)
{
	if (err == ERR_MEM)
		printf("%s: allocation error\n", bin);
	return (exit(err));
}

/*
** Get the line arguments from the user input.
*/

char		**get_args(char *line)
{
	int		i;
	int		buff;
	char	*token;
	char	**tokens;

	i = -1;
	buff = BUFF_SIZE;
	tokens = (char **)malloc(sizeof(char *));
	if (!tokens)
		ft_error(g_app, ERR_MEM);
	token = strtok(line, TOK_DELIM);
	while (token)
	{
		tokens[++i] = token;
		if (buff < i)
		{
			buff += BUFF_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!token)
				ft_error(g_app, ERR_MEM);
		}
		token = strtok(NULL, TOK_DELIM)
	}
	tokens[i] = NULL;
	return (tokens);
}

// -----------------------------------------------------------------------------

/*
** Read user input.
*/

int			read_input(char **line)
{
	int		ret;
	size_t	buffer;

	buffer = BUFF_SIZE;
	ret = getline(line, &buffer, stdin);
	return (line && ret != -1 ? EXIT_OK : EXIT_FAIL);
}

// -----------------------------------------------------------------------------

/*
** Shell looping function.
*/

int			sh_loop(char *bin, char *opt)
{
	int		ret;
	int		loop;
	char	*line;
	char	**args;

	ret = EXIT_OK;
	loop = 1;
	line = NULL;
	while (loop)
	{
		printf("🍍  > ");
		if ((ret = read_input(&line)) == EXIT_FAIL)
			break ;
		free(line);
	}
	return (ret);
}

// -----------------------------------------------------------------------------

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
		ret = sh_loop();
	else
		print_usage();
	return (ret);
}
