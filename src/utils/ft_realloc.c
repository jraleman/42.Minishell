/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 05:06:13 by jaleman           #+#    #+#             */
/*   Updated: 2016/12/10 05:06:13 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Change the size of the allocation pointed to by ptr to size, and returns ptr.
** If there is not enough room to enlarge the memory allocation pointed to by
** ptr, this function creates a new allocation, copies as much of the old data
** pointed to by ptr as will fit to the new allocation, frees the old
** allocation, and returns a pointer to the allocated memory.
** If ptr is NULL, this function is identical to malloc() for size bytes.
** If size is zero and ptr is not NULL, a new, minimum sized object is
** allocated and the original object is freed.
*/

void	*ft_realloc(char *str, size_t size)
{
	char	*p;
	size_t	i;

	p = NULL;
	i = 0;
	if (str)
	{
		p = (char *)malloc(sizeof(char) * (size));
		if (!p)
			return (NULL);
		ft_bzero(p, size);
		ft_strcpy(p, str);
		free(str);
		str = NULL;
	}
	return (p);
}
