/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:22:15 by hrice             #+#    #+#             */
/*   Updated: 2019/03/04 16:04:52 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "color.h"
#include "errors.h"

void	push(t_z_value **coords_stack, t_z_value *new)
{
	if (coords_stack)
	{
		if (new)
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

t_z_value	*pop(t_z_value **coords_stack)
{
	t_z_value	*top;

	top = NULL;
	if (coords_stack && *coords_stack)
	{
		top = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return (top);
}
int	ft_atoi_base(const char *str, int base)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_is_spase(str[i]))
		i++;
	if (base != 10 && !ft_prefix(&str[i], base))
		return (-1);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		sign = (str[i] == '-') ? -1 : 1;
	while (ft_is_digit_base(str[i++], base) >= 0)
		result = result * base + ft_is_digit_base(str[i++], base);
	return ((int)(result * sign));
}

void	stack_to_arr(t_z_value **coords_stack, t_map *map)
{
	t_z_value	*coord;
	ssize_t		i;
	size_t		arr_size;

	arr_size = map->width * map->height * sizeof(int);
	if (!(map->coords_arr = (int *)ft_memalloc(arr_size)))
		ft_error(ERR_CONV_TO_ARR);
	if (!(map->color_arr = (int *)ft_memalloc(arr_size)))
		ft_error(ERR_CONV_TO_ARR);
	i = map->width * map->height - 1;
	while ((coord = pop(coords_stack)) && i >= 0)
	{
		map->coords_arr[i] = coord->z;
		map->color_arr[i] = coord->color;
		if (coord->z > map->z_max)
			map->z_max = coord->z;
		if (coord->z < map->z_min)
			map->z_min = coord->z;
		i--;
		free(coord);
	}
	map->z_range = map->z_max - map->z_min;
}

int		get_index(int x, int y, int width)
{
	return (y * width + x);
}

int	get_default_color(int z, t_map *map)
{
	double	percentage;

	percentage = percent(map->z_min, map->z_max, z);
	if (percentage < 0.2)
		return (COLOR_DISCO);
	else if (percentage < 0.4)
		return (COLOR_BRICK_RED);
	else if (percentage < 0.6)
		return (COLOR_FLAMINGO);
	else if (percentage < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

t_point	new_point(int x, int y, t_map *map)
{
	t_point	point;
	int		index;

	index = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->coords_arr[index];
	point.color = (map->color_arr[index] == -1) ?
			get_default_color(point.z, map) : map->color_arr[index];
	return (point);
}
