/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_keycode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 22:53:22 by afukuhar          #+#    #+#             */
/*   Updated: 2020/11/17 23:01:08 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int print_keyhook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
}

int main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Printing the keycode presses! :D");
	mlx_key_hook(vars.win, print_keyhook, &vars);
	mlx_loop(vars.mlx);
}