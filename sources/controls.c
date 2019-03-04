/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:59:06 by hrice             #+#    #+#             */
/*   Updated: 2019/03/04 17:37:55 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

int		close()
{
	/* (void)param; */
	exit(0);
	return (0);
}

void	setup_controls(t_fdf *fdf)
{
	/* mlx_hook(fdf->win, 2, 0, key_press, fdf); */
	mlx_hook(fdf->win, 17, 0, close, fdf);
	/* mlx_hook(fdf->win, 4, 0, mouse_press, fdf); */
	/* mlx_hook(fdf->win, 5, 0, mouse_release, fdf); */
	/* mlx_hook(fdf->win, 6, 0, mouse_move, fdf); */
}
