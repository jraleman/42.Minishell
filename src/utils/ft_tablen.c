/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:08:37 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/15 17:08:39 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Return the number of entries in a table
*/

size_t		ft_tablen(char **tab)
{
	int		len;

	len = 0;
	while (tab[len] != NULL)
		len += 1;
	return (len);
}
