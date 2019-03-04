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

static int	launch_ps(char **args)
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
** Execute a command
*/

static int	run_cmd(char **args)
{
	int		ret;
	int		i;

	i = 1;
	if (args[0])
	{
		while (i < (int)builtins_total)
			if (!strcmp(args[0], builtin_str[i]))
				break ;
		ret = (i < (int)builtins_total \
			? (builtin_func[i](args)) : launch_ps(args));
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
	}
	return (ret);
}
