/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle_polygons.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:12:14 by afukuhar          #+#    #+#             */
/*   Updated: 2020/11/01 16:12:58 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

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
