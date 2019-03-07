/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:22:32 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/25 10:22:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// /*
// ** ...
// */
//
// static void	usage_msg()
// {
// 	fprintf(stderr, "usage: cd { path }\n");
// }

/*
** ...
*/

int			cmd_cd(char **args, char *bin)
{

	if (!args[1] && !args[2] && !args[3])
		fprintf(stderr, "%s: expected argument to \"cd\"\n", bin);
		// usage_msg();
	else
		chdir(args[1]) ? perror(bin) : 0;
	return (1);
}
