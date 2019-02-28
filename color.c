/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:21:12 by hrice             #+#    #+#             */
/*   Updated: 2019/02/26 17:56:44 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_light(int start, int finish, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * finish));
}

int		get_color(t_point cur, t_point start, t_point finish, t_point delta)
{
	int	red;
	int	green;
	int	blue;
	double	percentage;

	if (cur.color == finish.color)
		return (cur.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, finish.x, cur.x);
	else
		percentage = percent(start.y, finish.y, cur.y);
	red = get_light((start.color >> 16) & 0xFF, (finish.color >> 16) & 0xFF,
					percentage);
	green = get_light((start.color >> 8) & 0xFF, (finish.color >> 8) & 0xFF,
					percentage);
	blue = get_light(start.color & 0xFF, finish.color & 0xFF,
					percentage);
	return ((red << 16) | (green << 8) | blue);
}
