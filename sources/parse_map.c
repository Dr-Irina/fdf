/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:27:20 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/03/07 20:10:10 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_z_val type, ft_error(), ft_isnumber(), ft_atoi_base(),
**  t_map type and push()
** "libft.h" for size_t type ("libft.h" includes <string.h>), ft_memalloc()
**  ft_strsplit(), ft_atoi(), NULL macros ("libft.h" includes <string.h>)
**  and ft_strdel()
** "get_next_line.h" for get_next_line()
** "error_message.h" for ERR_MAP_READING macros and ERR_MAP macros
** <stdlib.h> for free()
*/

#include "fdf.h"
#include "libft.h"
#include "errors.h"
#include <stdlib.h>

/*
** Free array that was returned by ft_strsplit()
*/

/* static void			free_strsplit_arr(char **arr) */
/* { */
/* 	size_t i; */

/* 	i = 0; */
/* 	while (arr[i]) */
/* 		free(arr[i++]); */
/* 	free(arr); */
/* } */

/*
** Create t_z_val element with information about z and color value
*/

static t_z_val	*new_coord(char *s)
{
	t_z_val	*coord;
	char		**parts;

	if (!(coord = (t_z_val *)ft_memalloc(sizeof(t_z_val))))
		ft_error(ERR_MAP_READING);
	if (!(parts = ft_strsplit(s, ',')))
		ft_error(ERR_MAP_READING);
	if (!ft_isnumber(parts[0], 10))
		ft_error(ERR_MAP_READING);
	if (parts[1] && !ft_isnumber(parts[1], 16))
		ft_error(ERR_MAP_READING);
	coord->z = ft_atoi(parts[0]);
	coord->color = parts[1] ? ft_atoi_base(parts[1], 16) : -1;
	coord->next = NULL;
	ft_free_arr(parts);
	return (coord);
}

/*
** Get coordinate values from line, create t_z_val elements
** and them add to stack
*/

static void			parse_line(char **coords_line,
							t_z_val **coords_stack,
							t_map *map)
{
	int	width;

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

/*
** Read map from file line by line
*/

int					read_map(const int fd,
							t_z_val **coords_stack,
							t_map *map)
{
	char	*line;
	int		result;
	char	**coords_line;

	while ((result = get_next_line(fd, &line)) == 1)
	{
		if (!(coords_line = ft_strsplit(line, ' ')))
			ft_error(ERR_MAP_READING);
		parse_line(coords_line, coords_stack, map);
		ft_free_arr(coords_line);
		ft_strdel(&line);
		map->height++;
	}
	if (!(*coords_stack))
		ft_error(ERR_MAP);
	return (result);
}
