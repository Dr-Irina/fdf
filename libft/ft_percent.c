/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:06:02 by hrice             #+#    #+#             */
/*   Updated: 2019/03/02 17:06:02 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	percent(int start, int finish, int cur)
{
	int	place;
	int interval;

	place = cur - start;
	interval = finish - start;
	return ((interval = 0) ? 1.0 : (place / interval));
}
