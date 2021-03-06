/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:20:12 by afukuhar          #+#    #+#             */
/*   Updated: 2021/01/10 16:28:50 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int             x_close()
{
	printf("closing with x\n");
	exit(1);
	return (0);
}

int				esc_close(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_ESC)
	{
		printf("closing with esc\n");
		exit(1);
	}
	return (0);
}
