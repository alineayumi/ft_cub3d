/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 00:14:01 by afukuhar          #+#    #+#             */
/*   Updated: 2020/11/18 22:10:45 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

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

// int				entered_window(int event, int x, int y, t_vars *vars)
// {
// 	printf("ev: %d\n", event);
// 	printf("1L<<4: %ld\n", 1L<<4);

// 	if ( == MASK_ENTERWINDOW)
// 		printf("Hello!");
// 	if (event == LeaveNotify)
// 		printf("Bye");
// 	return (0);
// }

int             main(void)
{
    t_vars    vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
    mlx_hook(vars.win, KeyPress, MASK_KEYPRESS, esc_close, &vars);
	mlx_hook(vars.win, DestroyNotify, MASK_BUTTONPRESS, x_close, &vars);
	// mlx_mouse_hook(vars.win, entered_window, &vars);
    mlx_loop(vars.mlx);
} 
