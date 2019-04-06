/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:22:32 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/25 10:22:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			cmd_unsetenv(char **args, char **env, char *name)
{
	char	**ep;
	char	*sp;
	size_t	len;

	(void)name;
	if (!args[1] || strchr(args[1], '='))
		puts("Error");
	else
	{
		len = strlen(args[1]);
		for (ep = env; *ep;)
		{
			if (!strncmp(*ep, args[1], len) && (*ep)[len] == '=')
			{
				for (sp = *ep; *sp; sp += 1)
				{
					*sp = *(sp + 1);
					// printf("%s\n", sp);
					// *sp = *sp++;
				}
			}
			else
				ep += 1;
		}
	}
	return (1);
}
