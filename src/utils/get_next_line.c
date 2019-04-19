/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:44:35 by jaleman           #+#    #+#             */
/*   Updated: 2017/03/20 13:44:37 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_read(const int fd, char **s)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		i;

	if ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		tmp = *s;
		*s = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[4864];
	char		*end_s;
	int			k;

	if (fd < 0 || fd > 2048 - 1 || line == NULL)
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(1);
	while ((end_s = ft_strchr(s[fd], '\n')) == NULL)
	{
		if ((k = ft_read(fd, &s[fd])) < 0)
			return (-1);
		if (k == 0 && !end_s)
		{
			if (s[fd][0] == '\0')
				return (0);
			*line = s[fd];
			s[fd] = NULL;
			return (1);
		}
	}
	*line = ft_strsub(s[fd], 0, end_s - s[fd]);
	s[fd] = ft_strdup(end_s + 1);
	return (1);
}
