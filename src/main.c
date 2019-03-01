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
// fork(); execvp();   |||||||||    execve();
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** Macros
*/

# define EXIT_OK		(0)
# define EXIT_FAIL		(-1)
# define ERR_MEM		(-2)
# define BUFF_SIZE		(64)
# define TOK_DELIM		(" \t\r\n\a")
# define CMD_PRMPT		("🍍  > ")

/*
** Globals
*/

char	*g_app = NULL;

// -----------------------------------------------------------------------------
// utils.c

void		ft_error(char *bin, int err)
{
	if (err == ERR_MEM)
		printf("%s: allocation error\n", bin);
	return (exit(err));
}

// -----------------------------------------------------------------------------
// sh_loop.c

/*
** Get the line arguments from the user input.
*/

static char	**get_args(char *line)
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
			tokens = realloc(tokens, buff * sizeof(char *));
			if (!token)
				ft_error(g_app, ERR_MEM);
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}

/*
** Read user input.
*/

static int	read_input(char **line)
{
	int		ret;
	size_t	buffer;

	buffer = BUFF_SIZE;
	ret = getline(line, &buffer, stdin);
	return (line && ret != -1 ? EXIT_OK : EXIT_FAIL);
}

/*
** Starts a new process to run a command.
*/

static int	run_cmd(char **args)
{
	int		ret;
	int		status;
	pid_t	pid;
	pid_t	wpid;

	ret = 1;
	status = 0;
	pid = fork();
	if (!pid)
	{
		// child
		if (execvp(args[0], args) == -1)
		// if (execve(args[0], args) == -1)
			perror("minishell"); // ???
		ret = EXIT_FAIL;
	}
	else if (pid < 0)
		perror("minishell");
	else
	{
		// while (status && !WIFEXITED(status))
		// printf("%i\n", status);
		wpid = waitpid(pid, &status, WUNTRACED);
		// printf("%i\n", status);
		// printf("%d\n", wpid);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (ret);
}

/*
** Shell looping function.
*/

int			sh_loop(void)
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
		printf(CMD_PRMPT);
		if ((ret = read_input(&line)) == EXIT_FAIL)
			break ;
		args = get_args(line);
		if ((ret = run_cmd(args)) == EXIT_FAIL)
			break ;
		free(line);
		line = NULL;
		free(args);
		// args = NULL;
	}
	return (ret);
}

// -----------------------------------------------------------------------------
// main.c

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
