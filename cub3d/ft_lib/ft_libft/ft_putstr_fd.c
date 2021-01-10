/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:54:15 by afukuhar          #+#    #+#             */
/*   Updated: 2021/01/09 22:32:06 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		len += ft_putchar_fd(*s, fd);
		s++;
	}
	return (len);
}
