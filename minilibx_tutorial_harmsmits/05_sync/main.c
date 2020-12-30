/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:14:42 by afukuhar          #+#    #+#             */
/*   Updated: 2020/12/30 14:40:12 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int	change_position(int keycode, t_vars *vars);

int	render_next_frame(t_vars *vars)
{
	t_data img;
	t_point c;
	t_polygon polygon;

	img.img = mlx_new_image(vars->mlx,500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	
	set_point(vars->pos_x, vars->pos_y, &c);
	draw_circle(&img, 20, c, 0x0000FF00);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, img.img);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, vars->win);
}	

int	change_position(int keycode, t_vars *vars) 
{
	if (keycode == KEY_W && vars->pos_y > 25)
		vars->pos_y -= 10;
	else if (keycode == KEY_A && vars->pos_x > 25)
		vars->pos_x -= 10;
	else if (keycode == KEY_S && vars->pos_y < 475)
		vars->pos_y += 10;
	else if (keycode == KEY_D && vars->pos_y < 475)
		vars->pos_x += 10;
}

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


int	main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello World!");
	vars.pos_x = 250;
	vars.pos_y = 250;
	
	mlx_key_hook(vars.win, change_position, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_hook(vars.win, KeyPress, MASK_KEYPRESS, esc_close, &vars);
	mlx_hook(vars.win, DestroyNotify, MASK_BUTTONPRESS, x_close, &vars);
	mlx_loop(vars.mlx);
}