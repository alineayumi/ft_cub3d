/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 10:43:47 by afukuhar          #+#    #+#             */
/*   Updated: 2021/01/09 22:21:04 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define FD_SIZE 65535

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int		get_next_line(int fd, char **line);
void	ft_bzero(void *s, size_t n);
char	*ft_strnew(size_t size);
size_t	ft_strlcpy(char *restrict dst, const char *restrict src,
	size_t dstsize);
size_t	ft_strlcat(char *restrict dst, const char *restrict src,
	size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s1, unsigned int start, size_t len);
int		ft_delete(char *str);
#endif
