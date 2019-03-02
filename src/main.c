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
# define AUTHOR			("Jose Ramon Aleman")

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
// builtins.c

char		*builtin_str[] =
{
  "cd",
  "help",
  "exit"
};

int			(*builtin_func[])(char **) =
{
	&cmd_cd,
	&cmd_help,
	&cmd_exit
};

int			builtins_total(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

// -----------------------------------------------------------------------------
// cmd/cmd_exit.c

int			cmd_exit(void)
{
	return (EXIT_OK)
}

// -----------------------------------------------------------------------------
// cmd/cmd_cd.c

int			cmd_cd(char **args)
{
	if (!args[1])
		fprintf(stderr, "%s: expected argument to \"cd\"\n", g_app);
	else
		if (chdir(args[1]))
			perror(g_app);
	return (1);
}

// -----------------------------------------------------------------------------
// cmd/cmd_help.c

void		print_info(void)
{
	printf("%s's Minishell\n", AUTHOR);
	printf("Type program names and arguments, and hit enter.\n");
	return ;
}

int			cmd_help(void)
{
	int		i;

	i = 0;
	print_info();
	printf("The following are built in:\n");
	while (i < builtins_total)
		printf("    %s\n", builtin_str[i]);
	printf("Use the man command for information on other programs.\n");
	return (1);
}

// -----------------------------------------------------------------------------
// minishell.c

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
			perror(g_app); // ???
		ret = EXIT_FAIL;
	}
	else if (pid < 0)
		perror(g_app);
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

int			minishell(void)
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
		ret = minishell();
	else
		print_usage();
	return (ret);
}
