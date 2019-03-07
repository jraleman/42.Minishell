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

char		*g_builtin_str[] =
{
  "exit", "help", "env", "setenv", "cd", "echo", "baguette", "konami"
};
int			(*g_builtin_func[])(char **) =
{
  &cmd_exit, &cmd_help, &cmd_env, &cmd_setenv, &cmd_cd, &cmd_echo
              , &cmd_baguette, &cmd_konami
};

/*
** Read user input.
*/

static int	read_input(char **line)
{
	int		ret;
	size_t	buffer;

	buffer = BUFF_SIZE;
	ret = getline(line, &buffer, stdin);
	return (line && ret != -1 ? EXIT_SUCCESS : EXIT_FAILURE);
}

/*
** Get the line arguments from the user input.
*/

static char	**get_args(char *line, char *bin)
{
	int		i;
	int		buff;
	char	*token;
	char	**tokens;

	i = -1;
	buff = BUFF_SIZE;
	tokens = (char **)malloc(sizeof(char *));
	if (!tokens)
		ft_error(bin, ERR_MEM);
	token = (line ? strtok(line, TOK_DELIM) : NULL);
	while (token)
	{
		tokens[++i] = token;
		if (buff < i)
		{
			buff += BUFF_SIZE;
			tokens = realloc(tokens, buff * sizeof(char *));
			if (!token)
				ft_error(bin, ERR_MEM);
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[++i] = NULL;
	return (tokens);
}

/*
** Starts a new process to run a command.
*/

static int	launch_ps(char **args, char *bin)
{
	int		ret;
	int		status;
	pid_t	pid;
	pid_t	wpid;

	ret = 1;
	status = 1;
	wpid = 0;
	pid = fork();
	if (args && !pid)
	{
		printf("process doesn't exist\n");
		if (execvp(args[0], args) == -1)
			perror(bin);
		ret = 0;
	}
	else if (pid < 0)
	{
		printf("general error\n");
		perror(bin);
	}
	else
	{
		// ???
		// wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (ret);
}

/*
** Execute a command
*/

static int	run_cmd(char **args)
{
	int		ret;
	int		i;

	i = -1;
	ret = 1;
	if (args && *args)
	{
		while (++i < BLTNS_NUM)
		{
			if (!strcmp(args[0], (char *)g_builtin_str[i]))
				break ;
		}
		ret = (i < BLTNS_NUM ? ((int)g_builtin_func[i](args)) \
				: launch_ps(args));
	}
	return (ret);
}

/*
** Shell looping function.
*/

int			minishell(char *bin, char *opt)
{
	int		ret;
	int		loop;
	char	*prmpt;
	// t_sh	sh;
	char	*line;
	char	**args;

	ret = EXIT_SUCCESS;
	loop = 1;
	line = NULL;
	// t_sh = set_options(t_sh sh, char *opt[])
	while (loop)
	{
		prmpt = (opt && !strcmp(opt, "varela") ? PRMPT_BNS : PRMPT_DFL);
		printf(CMD_PRMPT(PRMPT_DFL));
		if ((ret = read_input(&line)) == EXIT_FAILURE)
			break ;
		args = get_args(line);
		loop = run_cmd(args);
		free(line);
		line = NULL;
		free(args);
		args = NULL;
	}
	ret == EXIT_FAILURE ? printf("WTF?!\n") : printf("Bye!\n");
	return (ret);
}
