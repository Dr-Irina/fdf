/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:29:16 by hrice             #+#    #+#             */
/*   Updated: 2019/03/05 17:07:54 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 720
# define WIDTH 1080
# define MENU_WIDTH 150

#include "mlx.h"
#include "libft.h"
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
	int					z_min;
	int					z_max;
	int					z_range;
	int					*coords_arr;
	int					*color_arr;
	int					*color;
}						t_map;

typedef enum			e_projection
{
						ISO,
						PARALLEL
}						t_projection;

typedef struct			s_camera
{
	t_projection		projection;
	int					zoom;
	double				alpha;
	double				beta;
	double				gamma;
	float				z_divisor;
	int					x_offset;
	int					y_offset;
}						t_camera;

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
	t_camera			*camera;
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
t_camera		*camera_init(t_fdf *fdf);
int				ft_atoi_base(const char *str, int base);
void			free_arr(char **arr);
t_z_value		*new_coord(char *str);
void 			parse_line(char **coords_line, t_z_value **coords_stack, t_map *map);
int				read_map(int fd, t_z_value **coords_stack, t_map *map);
void			push(t_z_value **coords_stack, t_z_value *new);
int				ft_atoi_base(const char *str, int base);
void			draw(t_map *map, t_fdf *fdf);
void			stack_to_arr(t_z_value **coords_stack, t_map *map);
t_z_value		*pop(t_z_value **coords_stack);
void			push(t_z_value **coords_stack, t_z_value *new);
void			rotate_x(int *y, int *z, double alpha);
void			rotate_y(int *x, int *z, double beta);
void			rotate_z(int *x, int *y, double gamma);
void			rotate_z(int *x, int *y, double gamma);
t_point			project(t_point p, t_fdf *fdf);
int				get_index(int x, int y, int width);
int				get_default_color(int z, t_map *map);
t_point			new_point(int x, int y, t_map *map);
t_point			project(t_point p, t_fdf *fdf);
int				close();
void			setup_controls(t_fdf *fdf);

#endif
