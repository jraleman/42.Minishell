/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_total.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:22:32 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/25 10:22:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// char		*g_builtin_str[];

/*
** ...
*/

int			builtins_get_total(void)
{
	// printf("%s\n", g_builtin_str[0]);
	// return (sizeof(g_builtin_str) / sizeof(char *));
	// return (BLTNS_NUM / sizeof(char *));
	return (BLTNS_NUM);
	// return (8);
}
