/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:48:53 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/03/07 20:02:48 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_z_val type
** <stdlib.h> for NULL macros
*/

#include "fdf.h"
#include <stdlib.h>

/*
** Add t_z_val element to stack
*/

void		push(t_z_val **coords_stack, t_z_val *new)
{
	if (coords_stack)
	{
		if (new)
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

/*
** Get t_z_val element from stack
*/

t_z_val	*pop(t_z_val **coords_stack)
{
	t_z_val *top;

	top = NULL;
	if (coords_stack && *coords_stack)
	{
		top = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return (top);
}
