/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:10:30 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/22 19:10:31 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cmd_pwd(char **args, char **env)
{
	char	buf[PATH_MAX + 1];
	int		i;

	i = 0;
	while (args[i])
		i++;
	// (i > 1) ? ft_printf("pwd: too many arguments\n") : 0;
	(i > 1) ? write(1, "pwd: too many arguments\n", ft_strlen("pwd: too many arguments\n")) : 0;
	(i == 1) ? write(1, getcwd(buf, PATH_MAX), ft_strlen(getcwd(buf, PATH_MAX))) : 0;
	write(1, "\n", 1);
	return (env);
}
