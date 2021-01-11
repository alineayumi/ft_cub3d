/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:22:43 by afukuhar          #+#    #+#             */
/*   Updated: 2021/01/10 13:19:41 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	return (0);
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
	return (0);
}

