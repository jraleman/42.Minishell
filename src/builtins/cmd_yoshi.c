/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_squirtle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:33:58 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/22 17:33:59 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// https://github.com/markotikvic/cowsay/blob/master/main.c
/*
char cow[] ="\n\
     \\  ^__^              \n\
      \\ (oo)\\______      \n\
        (__)\\      )\\/\\ \n\
            ||---w |       \n\
            ||    ||       \n";
*/

char	*squirtle(void)
{
	return ("\
       _.-~~~~~~~-.              \n\
      /         _   ~.            \n\
     |#`       /#`    \\           \n\
     |-'|      |-'|    |          \n\
     /--        --     |-.        \n\
     \\__   .  .        / /\\_      \n\
      \\ ~~--___---~~/\\| |   ~-.   \n\
   .---`~~--____---_)  \\ \\-__  \\  \n\
  ) <    |__    __\\_   \\ \\     | \n\
   ~-.__ /   ~~~~   \\   \\ \\     | \n\
        ~-.   |     .~-.-' |    | \n\
         | \\___|___/     / /     |\n\
         | /   |   \\     | |  /  |\n\
          \\     |   ~-___ \\ \\/  / \n\
          /\\__ / `._ /   ~-\\ \\_/  \n\
         /    \\_____|      |`~    \n\
        |      |    |      |      \n\
         \\     |    |      |      \n\
         >______)   /_/\\/\\_\\      \n\n");
}

/*
** ...
*/

void print_usage()
{
    printf("Usage: cowsay \"<your text goes here>\"\n");
}

/*
** ...
*/

void dashed_line(int l)
{
    printf(" ");
    for (int i = 0; i < l+2; i++)
        printf("_");
    printf(" \n");
}

/*
** ...
*/

char		**cmd_yoshi(char **args, char **env, char *name)
{
	int		lsize;
	char	*poke;

	if (!args[0] || args[2])
		print_usage();
	else
	{
		lsize = ft_strlen(args[1]);
		poke = squirtle();
		dashed_line(lsize);
		printf("\n");
		printf("< %s >\n", args[1]);
		dashed_line(lsize);
		printf("%s\n", poke);
	}
	return (env);
	(void)name;
}
