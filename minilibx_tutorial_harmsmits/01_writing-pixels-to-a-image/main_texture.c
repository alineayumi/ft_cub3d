/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:58:20 by afukuhar          #+#    #+#             */
/*   Updated: 2020/11/03 16:20:18 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

int		main(void)
{
	t_data		img;
	void		*mlx;
	void		*mlx_win;
	t_polygon	polygon;
	t_point		c;
	int x = 0;
	int y;
	int max_x = 500;
	int max_y = 500;
	int w = 10;
	int h = 10;
	int color = 0x00FF0000;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, max_x, max_y, "My first image");
	img.img = mlx_new_image(mlx, 100, 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	set_point(5, 5, &c);
	set_polygon(c, 3, 4, &polygon);
	draw_nsides(&img, polygon, color);

	while (x < max_x)
	{
		y = 0;
		while (y < max_y)
		{
			mlx_put_image_to_window(mlx, mlx_win, img.img, x, y);
			y += h;
		}
		x += w;
	}
	mlx_loop(mlx);
}
