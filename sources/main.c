/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:24:26 by hrice             #+#    #+#             */
/*   Updated: 2019/03/05 16:40:01 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

int			main(int ac, char **av)
{
	int			fd;
	t_map		*map;
	t_z_value	*coords_stack;
	t_fdf		*fdf;

	errno = 0;
	if (ac == 2)
	{
		if (!((fd = open(av[1], O_RDONLY)) >= 0))
			ft_error(ERR_MAP);
		map = map_init();
		if (read_map(fd, &coords_stack, map) == -1)
			ft_error("1");
		fdf = fdf_init(map);
		stack_to_arr(&coords_stack, map);
		fdf->camera = camera_init(fdf);
		draw(fdf->map, fdf);
		/* setup_controls(fdf); */
		mlx_loop(fdf->mlx);
	}
	ft_error(ERR_USAGE);
	return (0);
}
