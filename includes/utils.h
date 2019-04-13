/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:32:09 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/02 15:32:11 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** Header files dependencies.
*/

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

/*
** Get next line macros
*/

# define BUFF_SIZE		(1024)

/*
** List of globlal variables.
*/

# ifndef GLOBAL_VAR
#  define GLOBAL_VAR

static const unsigned long	g_mask01;
static const unsigned long	g_mask80;

# endif

/*
** Function prototypes.
*/

int			get_next_line(const int fd, char **line);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_strncat(char *s1, const char *s2, size_t n);
char		*ft_strncat(char *s1, const char *s2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
void		ft_bzero(void *s, size_t n);
void		ft_strclr(char *s);
void		ft_error(int err, char *exe, char *msg);
size_t		ft_strlen(const char *s);

#endif
