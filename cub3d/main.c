/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:14:42 by afukuhar          #+#    #+#             */
/*   Updated: 2020/12/30 16:24:17 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Reading a map");
	
	mlx_hook(vars.win, KeyPress, MASK_KEYPRESS, esc_close, &vars);
	mlx_hook(vars.win, DestroyNotify, MASK_BUTTONPRESS, x_close, &vars);
	mlx_loop(vars.mlx);
}