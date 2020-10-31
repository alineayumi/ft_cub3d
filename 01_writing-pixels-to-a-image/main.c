/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:58:20 by afukuhar          #+#    #+#             */
/*   Updated: 2020/10/31 00:55:04 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "image.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int edge, int start_x, int start_y, int color)
{
	int i;

	i = 0;
	while (i < edge)
	{
		my_mlx_pixel_put(data, start_x, start_y + i, color);
		my_mlx_pixel_put(data, start_x + i, start_y, color);
		my_mlx_pixel_put(data, start_x + edge, start_y + i, color);
		my_mlx_pixel_put(data, start_x + i, start_y + edge, color);
		i++;
	}
}

int 	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "My first image");
	img.img = mlx_new_image(mlx, 500, 500);

	/*
    ** After creating an image, we can call `mlx_get_data_addr`, we pass
    ** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
    ** then be set accordingly for the *current* data address.
    */
   img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
   draw_square(&img, 100, 100, 100, 0x00FF0000);
   mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
   mlx_loop(mlx);
}