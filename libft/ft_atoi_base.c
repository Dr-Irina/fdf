/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:03:27 by hrice             #+#    #+#             */
/*   Updated: 2019/03/07 15:17:54 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *str, int base)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_is_space(str[i]))
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
