/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:20:12 by afukuhar          #+#    #+#             */
/*   Updated: 2020/12/30 16:21:16 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int             x_close()
{
	printf("closing with x\n");
	exit(1);
	return (0);
}

int				esc_close(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		printf("closing with esc\n");
		exit(1);
	}
	return (0);
}
