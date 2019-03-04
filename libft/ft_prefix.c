/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:10:45 by hrice             #+#    #+#             */
/*   Updated: 2019/03/02 16:59:05 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_prefix(const char *str, int base)
{
	size_t	i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (-1);
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (1);
		if (base == 8)
			return (1);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (1);
	}
	return (-1);
}
