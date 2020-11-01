/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:58:20 by afukuhar          #+#    #+#             */
/*   Updated: 2020/11/01 16:14:25 by afukuhar         ###   ########.fr       */
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

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "My first image");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);

	set_point(400, 200, &c);
	draw_circle(&img, 40, c, 0x0000FF00);

	set_point(100, 100, &c);
	set_polygon(c, 3, 40, &polygon);
	draw_nsides(&img, polygon, 0x00FF0000);

	set_point(200, 100, &c);
	set_polygon(c, 4, 40, &polygon);
	draw_nsides(&img, polygon, 0x00FF0000);

	set_point(300, 100, &c);
	set_polygon(c, 5, 40, &polygon);
	draw_nsides(&img, polygon, 0x00FF0000);

	set_point(400, 100, &c);
	set_polygon(c, 6, 40, &polygon);
	draw_nsides(&img, polygon, 0x00FF0000);

	set_point(100, 200, &c);
	set_polygon(c, 7, 40, &polygon);
	draw_nsides(&img, polygon, 0x00FF0000);

	set_point(200, 200, &c);
	set_polygon(c, 8, 40, &polygon);
	draw_nsides(&img, polygon, 0x00FF0000);

	set_point(300, 200, &c);
	set_polygon(c, 9, 40, &polygon);
	draw_nsides(&img, polygon, 0x00FF0000);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
