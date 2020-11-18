/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 23:26:16 by afukuhar          #+#    #+#             */
/*   Updated: 2020/11/17 23:38:07 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int print_mouse_postion(int z, int x, int y, t_vars *vars)
{
	printf("x: %d | y: %d | z: %d\n", x, y, z);
}

int main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Printing the keycode presses! :D");
	mlx_mouse_hook(vars.win, print_mouse_postion, &vars);
	mlx_loop(vars.mlx);
}