/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:22:32 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/25 10:22:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** - printf()
*/
# include <stdio.h>
# include <string.h>

/*
** - exit()
*/
# include <stdlib.h>

/*
** Defined macros
*/
# define ERR_MEM	(2)

/*
** Function prototypes
*/
void			ft_error(char *bin, int err);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
