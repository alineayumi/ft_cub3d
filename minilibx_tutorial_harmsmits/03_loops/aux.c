/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:10:31 by afukuhar          #+#    #+#             */
/*   Updated: 2020/11/19 14:10:40 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Draws a single point on the window in p coordinate, with the specified color
*/
void	my_mlx_pixel_put(t_data *data, t_point p, int color)
{
	char *dst;

	dst = data->addr + (p.y * data->line_length +
		p.x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*
** Set the values passed as argument to a polygon
** Center cordinates, number of sides, radius size.
*/
void	set_polygon(t_point c, int sides, int radius, t_polygon *polygon)
{
	polygon->xc = c.x;
	polygon->yc = c.y;
	polygon->radius = radius;
	polygon->sides = sides;
}

/*
** Set the cordinates passed as argument to a point
*/
void	set_point(int x, int y, t_point *p)
{
	p->x = x;
	p->y = y;
}
