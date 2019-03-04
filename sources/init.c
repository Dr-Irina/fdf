/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:37:56 by hrice             #+#    #+#             */
/*   Updated: 2019/03/04 17:36:10 by hrice            ###   ########.fr       */
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
	map->z_min = -2147483648;
	map->z_max = 2147483647;
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
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bpp),
				&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	return(fdf);
}

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
		ft_error(ERR_CAMERA_INIT);
	camera->zoom = ft_min((WIDTH - MENU_WIDTH) / fdf->map->width / 2,
												HEIGHT / fdf->map->height / 2);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}
