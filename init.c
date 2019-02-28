/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:37:56 by hrice             #+#    #+#             */
/*   Updated: 2019/02/27 14:23:33 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

t_map		*map_init()
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		ft_error(ERR_MAP_INIT);
	map->width = 0;
	map->height = 0;
	map->color_arr = NULL;
	map->z_range = 0;
	return (map);
}

t_fdf		*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		ft_error(ERR_FDF_INIT);
	if (!(fdf->mlx = mlx_init()))
		ft_error(ERR_FDF_INIT);
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF")))
		ft_error(ERR_FDF_INIT);
	if (!(fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
		ft_error(ERR_FDF_INIT);
	/* fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bpp, */
	/* 			&(fdf->size_line), &(fdf->endian))); */
	fdf->map = map;
	return(fdf);
}
