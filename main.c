/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:24:26 by hrice             #+#    #+#             */
/*   Updated: 2019/02/27 14:41:33 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"

int			main(int ac, char **av)
{
	int		fd;
	t_map	*map;
	t_fdf	*fdf;

	errno = 0;
	if (ac == 2)
	{
		if (!(fd = open(av[1], O_RDONLY) >= 0))
			ft_error(ERR_MAP);
		map = map_init();
		fdf = fdf_init(map);
		mlx_loop(fdf->mlx);
	}
	ft_error(ERR_USAGE);
	return (0);
}
