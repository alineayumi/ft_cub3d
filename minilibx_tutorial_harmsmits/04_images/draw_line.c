/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:10:31 by afukuhar          #+#    #+#             */
/*   Updated: 2020/11/19 14:09:10 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Draws a line based on 2 points
*/

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

/*
** Based on 2 points defines which axis has the biggest dimension
** this will be the one to iterate
*/

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

/*
** Based on 2 points and the axis, defines which one is closest to the origin
*/

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
