/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:18:05 by afukuhar          #+#    #+#             */
/*   Updated: 2020/11/01 16:29:02 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

#include <math.h>
#include "../mlx/mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_line
{
	int x0;
	int y0;
	int xf;
	int yf;
}				t_line;

typedef struct	s_polygon
{
	int xc;
	int yc;
	int radius;
	int sides;
}				t_polygon;

void	my_mlx_pixel_put(t_data *data, t_point p, int color);
void	draw_circle(t_data *data, int radius, t_point c, int color);
char	axis_loop(t_point p1, t_point p2);
int		start_point(t_point p1, t_point p2, char axis);
void	draw_line(t_data *data, t_point p1, t_point p2, int color);
void	draw_nsides(t_data *data, t_polygon polygon, int color);
void	set_polygon(t_point c, int sides, int radius, t_polygon *polygon);
void	set_point(int x, int y, t_point *p);

#endif
