/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:01:52 by hrice             #+#    #+#             */
/*   Updated: 2019/03/05 17:53:12 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
/* t_bool		ft_isnumber(char *str, int base) */
/* { */
/* 	size_t	i; */
/* 	size_t	digit; */

/* 	i = 0; */
/* 	digit = 0; */
/* 	while (ft_is_spase(str[i])) */
/* 		i++; */
/* 	if (base != 10 && !ft_prefix(&str[i], base)) */
/* 		return (false); */
/* 	if (base == 2 || base == 16) */
/* 		i += 2; */
/* 	else if (base == 8) */
/* 		i++; */
/* 	else if (base == 10 && (str[i] == '-' || str[i] == '+')) */
/* 		i++; */
/* 	while (ft_is_digit_base(str[i], base) >= 0) */
/* 	{ */
/* 		i++; */
/* 		digit++; */
/* 	} */
/* 	return ((!str[i] && digit) ? true : false); */
/* } */

t_bool			ft_isnumber(char *str, int base)
{
	size_t		i;
	size_t		digits;

	i = 0;
	digits = 0;
	while (ft_is_space(str[i]))
		i++;
	if (base != 10 && !ft_prefix(&str[i], base))
		return (false);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (ft_is_digit_base(str[i], base) >= 0)
	{
		/* printf("RET: %d; I: %zd; DIGITS: %zd\n", ft_is_digit_base(str[i], base), i, digits); */
		i++;
		digits++;
	}
	printf("RET: %d; I: %zd; DIGITS: %zd\n", ft_is_digit_base(str[i], base), i, digits);
	return ((!str[i] && digits) ? true : false);
}
