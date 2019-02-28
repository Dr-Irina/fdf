/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:29:16 by hrice             #+#    #+#             */
/*   Updated: 2019/02/28 17:59:55 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 720
# define WIDTH 1080
# define MENU_WIDTH 150

#include "mlx.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct			s_map
{
	int					height;
	int					width;
	/* int				z_max; */
	int					z_range;
	int					*color_arr;
	int					*color;
}						t_map;

typedef struct			s_z_value
{
	int					z;
	int					color;
	struct s_z_value	*next;
}						t_z_value;

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bpp;
	int					size_line;
	int					endian;
	t_map				*map;
}						t_fdf;


void			put_pixel(t_fdf *fdf, int x, int y, int color);
void			draw_line(t_point start, t_point finish, t_fdf *fdf);
int   			get_light(int start, int finish, double percentage);
int				get_color(t_point cur, t_point start, t_point finish,
						t_point delta);
double			percent(int start, int finish, int cur);
t_map			*map_init();
t_fdf			*fdf_init(t_map *map);
int				ft_prefix(const char *str, int base);
int				ft_is_spase(int c);
int				ft_abs(int x);
void			ft_error(char *s);
int				ft_isnumber(char *str, int base);
int				ft_atoi_base(const char *str, int base);
int				ft_is_digit_base(char c, int base);

#endif
