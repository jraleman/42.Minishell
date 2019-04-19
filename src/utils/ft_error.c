/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 21:15:41 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/03 21:15:42 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_error(int err, char *exe, char *msg)
{
	// printf("%s: %s\n", exe, msg);
	write(1, exe, ft_strlen(exe));
	write(1, ": ", 2);
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	return (exit(err));
}
