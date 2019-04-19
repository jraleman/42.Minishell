/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:08:34 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/17 17:08:36 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Builtin exit command implementation.
*/

char		**cmd_exit(char **args, char **env, char *name)
{
	ft_tabfree(env);
	return (NULL);
	(void)args;
	(void)name;
}
