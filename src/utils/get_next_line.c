/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 07:11:51 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/26 07:11:52 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_not_bull(char *str)
{
	if (str[0] != '\0')
		return (1);
	return (0);
}

static char	*ft_strrsub(char *s, size_t len)
{
	char			*p;
	size_t			i;
	size_t			start;

	i = 0;
	if (!s)
		return (NULL);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	start = ft_strlen(s) - len;
	while (i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	ft_strclr(s);
	free(s);
	s = NULL;
	return (p);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char *save;
	int			ret;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if (!save)
		save = ft_strnew(BUFF_SIZE + 1);
	ft_bzero(buf, BUFF_SIZE + 1);
	while (!ft_strchr(buf, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		save = ft_realloc(save, ft_strlen(save) + ret + 1);
		save = ft_strncat(save, buf, ret);
	}
	if ((tmp = ft_strchr(save, '\n')))
	{
		*line = ft_strsub(save, 0, ft_strlen(save) - ft_strlen(tmp));
		save = ft_strrsub(save, ft_strlen(&tmp[1]));
		return (1);
	}
	*line = ft_strdup(save);
	ret = ft_not_bull(save);
	ft_strclr(save);
	return (ret == 0 ? 0 : 1);
}