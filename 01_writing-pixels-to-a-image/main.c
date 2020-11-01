/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:58:20 by afukuhar          #+#    #+#             */
/*   Updated: 2020/11/01 01:18:44 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "image.h"
#include <math.h>

void	my_mlx_pixel_put(t_data *data, t_point p, int color)
{
	char *dst;

	dst = data->addr + (p.y * data->line_length +
		p.x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_circle(t_data *data, int radius, t_point c, int color)
{
	int		i;
	t_point	p;

	i = 0;
	while (i < 360)
	{
		p.x = radius * cos(M_PI * i / 180) + c.x;
		p.y = c.y - radius * sin(M_PI * i / 180);
		my_mlx_pixel_put(data, p, color);
		i++;
	}
}

char	axis_loop(t_point p1, t_point p2)
{
	int delta_x;
	int delta_y;

	delta_x = (p1.x < p2.x ? p2.x - p1.x : p1.x - p2.x);
	delta_y = (p1.y < p2.y ? p2.y - p1.y : p1.y - p2.y);
	if (delta_x > delta_y)
		return ('x');
	return ('y');
}

int		start_point(t_point p1, t_point p2, char axis)
{
	if (axis == 'x')
	{
		if (p1.x < p2.x)
			return (1);
		else
			return (2);
	}
	else
	{
		if (p1.y < p2.y)
			return (1);
		else
			return (2);
	}
}

void	draw_line(t_data *data, t_point p1, t_point p2, int color)
{
	char	start;
	char	axis;
	t_line	l;
	t_point	p;

	axis = axis_loop(p1, p2);
	start = start_point(p1, p2, axis);
	l.x0 = (start == 1 ? p1.x : p2.x);
	l.y0 = (start == 1 ? p1.y : p2.y);
	l.xf = (start == 1 ? p2.x : p1.x);
	l.yf = (start == 1 ? p2.y : p1.y);
	p.x = l.x0;
	p.y = l.y0;
	while (axis == 'x' && p.x <= l.xf)
	{
		p.y = l.y0 + (p.x - l.x0) * (l.yf - l.y0) / (l.xf - l.x0);
		my_mlx_pixel_put(data, p, color);
		p.x++;
	}
	while (axis == 'y' && p.y <= l.yf)
	{
		p.x = l.x0 + (p.y - l.y0) * (l.xf - l.x0) / (l.yf - l.y0);
		my_mlx_pixel_put(data, p, color);
		p.y++;
	}
}

void	draw_nsides(t_data *data, t_polygon polygon, int color)
{
	int		vertex;
	double	teta_start;
	double	teta_end;
	t_point	p1;
	t_point	p2;

	vertex = 0;
	while (vertex < polygon.sides)
	{
		teta_start = vertex * (2 * M_PI / polygon.sides);
		teta_end = teta_start + (2 * M_PI / polygon.sides);
		p1.x = polygon.xc + (cos(teta_start) * polygon.radius);
		p1.y = polygon.yc - (sin(teta_start) * polygon.radius);
		p2.x = polygon.xc + (cos(teta_end) * polygon.radius);
		p2.y = polygon.yc - (sin(teta_end) * polygon.radius);
		draw_line(data, p1, p2, color);
		vertex++;
	}
}

void	set_polygon(t_point c, int sides, int radius, t_polygon *polygon)
{
	polygon->xc = c.x;
	polygon->yc = c.y;
	polygon->radius = radius;
	polygon->sides = sides;
}

void	set_point(int x, int y, t_point *p)
{
	p->x = x;
	p->y = y;
}

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
