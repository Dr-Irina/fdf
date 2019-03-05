/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:10:45 by hrice             #+#    #+#             */
/*   Updated: 2019/03/05 17:42:26 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/* t_bool	ft_prefix(const char *str, int base) */
/* { */
/* 	size_t	i; */

/* 	i = 0; */
/* 	if (base == 2 || base == 8 || base == 16) */
/* 	{ */
/* 		if (str[i++] != '0') */
/* 		{ */
/* 			printf("FT_PREFIX: %c, %d, %zd", str[i], base, i); */
/* 			return (false); */
/* 		} */
/* 		if (base == 2 && (str[i] == 'b' || str[i] == 'B')) */
/* 			return (true); */
/* 		if (base == 8) */
/* 			return (true); */
/* 		if (base == 16 && (str[i] == 'x' || str[i] == 'X')) */
/* 			return (true); */
/* 	} */
/* 	return (false); */
/* } */


t_bool	ft_prefix(const char *str, int base)
{
	size_t	i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (false);
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (true);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (true);
		if (base == 8)
			return (true);
	}
	return (false);
}
