/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:47:43 by hrice             #+#    #+#             */
/*   Updated: 2019/03/05 16:55:32 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errors.h"
#include "libft.h"

void		free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

/* t_z_value	*new_coord(char *str) */
/* { */
/* 	t_z_value	*coord; */
/* 	char		**part; */

/* 	if (!(coord = (t_z_value *)ft_memalloc(sizeof(t_z_value)))) */
/* 		ft_error("2"); */
/* 	if (!(part= ft_strsplit(str, ','))) */
/* 		ft_error("3"); */
/* 	if (!ft_isnumber(part[0], 10)) */
/* 		ft_error("4"); */
/* 	if (part[1] && !ft_isnumber(part[1], 16)) */
/* 		ft_error("5"); */
/* 	coord->z = ft_atoi(part[0]); */
/* 	coord->color = part[1] ? ft_atoi_base(part[1], 16) : -1; */
/* 	coord->next = NULL; */
/* 	free_arr(part); */
/* 	return (coord); */
/* } */

t_z_value	*new_coord(char *s)
{
	t_z_value	*coord;
	char		**parts;

	if (!(coord = (t_z_value *)ft_memalloc(sizeof(t_z_value))))
		ft_error(ERR_MAP_READING);
	if (!(parts = ft_strsplit(s, ',')))
		ft_error(ERR_MAP_READING);
	if (!ft_isnumber(parts[0], 10))
		ft_error("4");
	if (parts[1] && !ft_isnumber(parts[1], 16))
		ft_error(ERR_MAP_READING);
	coord->z = ft_atoi(parts[0]);
	coord->color = parts[1] ? ft_atoi_base(parts[1], 16) : -1;
	coord->next = NULL;
	free_arr(parts);
	return (coord);
}
void 		parse_line(char **coords_line, t_z_value **coords_stack, t_map *map)
{
	int		width;

	width = 0;
	while (*coords_line)
	{
		push(coords_stack, new_coord(*(coords_line++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;
	else if (map->width != width)
		ft_error(ERR_MAP);
}

int			read_map(int fd, t_z_value **coords_stack, t_map *map)
{
	char	*line;
	int		result;
	char	**coords_line;

	while ((result = get_next_line(fd, &line)) == 1)
	{
		if (!(coords_line = ft_strsplit(line, ' ')))
			ft_error("6");
		parse_line(coords_line, coords_stack, map);
		free_arr(coords_line);
		ft_strdel(&line);
		map->height++;
	}
	if (!(*coords_stack))
		ft_error(ERR_MAP);
	return (result);
}
