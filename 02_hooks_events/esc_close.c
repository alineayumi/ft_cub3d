/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 00:14:01 by afukuhar          #+#    #+#             */
/*   Updated: 2020/11/18 18:58:53 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int             close()
{
	printf("closing with x");
	exit(1);
	return (0);
}

int				esc_close(int keycode, t_vars *vars)
{
	printf("closing with esc");
	if (keycode == KEY_ESC)
		exit(1);
	return (0);
}

int             main(void)
{
    t_vars    vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
    mlx_hook(vars.win, KeyPress, MASK_KEYPRESS, close, &vars);
	mlx_hook(vars.win, DestroyNotify, MASK_BUTTONPRESS, close, &vars);
    mlx_loop(vars.mlx);
} 
