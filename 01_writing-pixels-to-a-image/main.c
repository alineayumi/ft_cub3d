/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:58:20 by afukuhar          #+#    #+#             */
/*   Updated: 2020/10/31 23:01:08 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "image.h"
#include <math.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int edge, int center_x, int center_y, int color)
{
	int i;
	int start_x = center_x - edge / 2;
	int start_y = center_y - edge / 2;

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

void	draw_circle(t_data *data, int radius, int center_x, int center_y, int color)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < 360)
	{
		x = radius * cos(M_PI * i / 180);
		y = radius * sin(M_PI * i / 180);
		my_mlx_pixel_put(data, center_x + x, center_y - y, color);
		i++;
	}
}

void	draw_triangle(t_data *data, int edge, int center_x, int center_y, int color)
{
	int i;
	int x;
	int y;
	int start_x;
	int start_y;

	start_x = center_x - edge / 2;
	start_y = center_y - edge * 2 / 3;
	i = 0;
	while (i <= edge)
	{
		x = i * cos(M_PI / 3);
		y = i * sin(M_PI / 3);
		my_mlx_pixel_put(data, start_x + x, start_y + edge - y, color);
		my_mlx_pixel_put(data, center_x + edge / 2 - x, start_y + edge - y, color);
		my_mlx_pixel_put(data, start_x + i, start_y + edge, color);
		i++;
	}
}

char	axis_loop(int x1, int x2, int y1, int y2)
{
	int delta_x;
	int delta_y;

	delta_x = (x1 < x2 ? x2 - x1 : x1 - x2);
	delta_y = (y1 < y2 ? y2 - y1 : y1 - y2);
	if (delta_x > delta_y)
		return ('x');
	return ('y');
}

int		start_point(int x1, int x2, int y1, int y2, char axis)
{
	if (axis == 'x')
	{
		if (x1 < x2)
			return (1);
		else
			return (2);
	}
	else
	{
		if (y1 < y2)
			return (1);
		else
			return (2);
	}
}

void	draw_line(t_data *data, int x1, int x2, int y1, int y2, int color)
{
	char axis;
	char start;
	int x_start;
	int y_start;
	int x_end;
	int y_end;
	int x;
	int y;

	axis = axis_loop(x1, x2, y1, y2);
	start = start_point(x1, x2, y1, y2, axis);
	x_start = (start == 1 ? x1 : x2);
	y_start = (start == 1 ? y1 : y2);
	x_end = (start == 1 ? x2 : x1);
	y_end = (start == 1 ? y2 : y1);
	x = x_start;
	y = y_start;
	if (axis == 'x')
		{
			while (x <= x_end)
			{
				y = y_start + (x - x_start) * (y_end - y_start) / (x_end - x_start);
				my_mlx_pixel_put(data, x, y, color);
				x++;
			}
		}
		else
		{
			while (y <= y_end)
			{
				x = x_start + (y - y_start) * (x_end - x_start) / (y_end - y_start);
				my_mlx_pixel_put(data, x, y, color);
				y++;
			}
		}

}

void	draw_nsides(t_data *data, int radius, int sides, int center_x, int center_y, int color)
{
	int vertex;
	double teta;
	double teta_start;
	double teta_end;
	int x1;
	int x2;
	int y1;
	int y2;
	int x;
	int y;
	int x_start;
	int x_end;
	int y_start;
	int y_end;
	char axis;
	int start;

	vertex = 0;
	teta = 2 * M_PI / sides;
	while (vertex < sides)
	{
		teta_start = vertex * teta;
		teta_end = teta_start + teta;
		x1 = center_x + (cos(teta_start) * radius);
		y1 = center_y - (sin(teta_start) * radius);
		x2 = center_x + (cos(teta_end) * radius);
		y2 = center_y - (sin(teta_end) * radius);
		axis = axis_loop(x1, x2, y1, y2);
		start = start_point(x1, x2, y1, y2, axis);
		x_start = (start == 1 ? x1 : x2);
		y_start = (start == 1 ? y1 : y2);
		x_end = (start == 1 ? x2 : x1);
		y_end = (start == 1 ? y2 : y1);
		x = x_start;
		y = y_start;
		if (axis == 'x')
		{
			while (x <= x_end)
			{
				y = y_start + (x - x_start) * (y_end - y_start) / (x_end - x_start);
				my_mlx_pixel_put(data, x, y, color);
				x++;
			}
		}
		else
		{
			while (y <= y_end)
			{
				x = x_start + (y - y_start) * (x_end - x_start) / (y_end - y_start);
				my_mlx_pixel_put(data, x, y, color);
				y++;
			}
		}
		vertex++;
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
//    draw_square(&img, 100, 100, 100, 0x00FF0000);
   draw_circle(&img, 40, 400, 200, 0x0000FF00);
//    draw_triangle(&img, 100, 100, 400, 0x000000FF);
   draw_nsides(&img, 40, 3, 100, 100, 0x00FF0000);
   draw_nsides(&img, 40, 4, 200, 100, 0x00FF0000);
   draw_nsides(&img, 40, 5, 300, 100, 0x00FF0000);
   draw_nsides(&img, 40, 6, 400, 100, 0x00FF0000);
   draw_nsides(&img, 40, 7, 100, 200, 0x00FF0000);
   draw_nsides(&img, 40, 8, 200, 200, 0x00FF0000);
   draw_nsides(&img, 40, 9, 300, 200, 0x00FF0000);

   mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
   mlx_loop(mlx);
}