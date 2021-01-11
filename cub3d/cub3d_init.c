/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afukuhar <afukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:41:43 by afukuhar          #+#    #+#             */
/*   Updated: 2021/01/10 16:24:44 by afukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		c3_init_map(t_cub3d *cub3d)
{
	cub3d->map.tile_size = 25;
	cub3d->map.num_rows = 20;
	cub3d->map.num_cols = 20;
	cub3d->map.win_h = cub3d->map.tile_size * cub3d->map.num_rows;
	cub3d->map.win_w = cub3d->map.tile_size * cub3d->map.num_cols;
	return (0);
}

int		c3_init_mlx(t_cub3d *cub3d)
{
	cub3d->vars.mlx = mlx_init();
	cub3d->vars.win = mlx_new_window(cub3d->vars.mlx, cub3d->map.win_w, cub3d->map.win_h, "Reading a map");
	return (0);
}