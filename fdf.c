/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:10:26 by hrice             #+#    #+#             */
/*   Updated: 2019/02/23 15:10:08 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf");
	img = create_img(mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT),
			0x212121, WIN_WIDTH, WIN_HEIGHT);
	/* mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF); */
	mlx_loop(mlx_ptr);
}
