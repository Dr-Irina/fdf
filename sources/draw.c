/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:16:02 by hrice             #+#    #+#             */
/*   Updated: 2019/02/28 16:31:39 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x > MENU_WIDTH && x < WIDTH && y > 0 && y < HEIGHT)
	{
		i = (x * fdf->bpp / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[i++] = color >> 8;
		fdf->data_addr[i++] = color >> 16;
	}
}

void		draw_line(t_point start, t_point finish, t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = ft_abs(finish.x - start.x);
	delta.y = ft_abs(finish.y - start.y);
	sign.x = start.x < finish.x ? 1 : -1;
	sign.y = start.y < finish.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = start;
	while (cur.x != finish.x || cur.y != finish.y)
	{
		put_pixel(fdf, cur.x, cur.y, get_color(cur, start, finish, delta));
		if ((error[0] * 2) > - delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

void		draw(t_map *map, t_fdf *fdf)
{
	int		x;
	int		y;

	/* draw_background(fdf); */
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != fdf->map->width - 1)
				draw_line(project(new_point(x, y, map), fdf),
					project(new_point(x + 1, y, map), fdf), fdf);
			if (y != fdf->map->height - 1)
				draw_line(project(new_point(x, y, map), fdf),
					project(new_point(x, y + 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	/* print_menu(fdf); */
}
