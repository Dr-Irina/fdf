/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:24:36 by wned              #+#    #+#             */
/*   Updated: 2019/01/31 19:47:44 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	nb;
	long long	result;

	nb = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\r' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = nb;
		nb = (nb * 10) + str[i++] - '0';
		if (nb < result)
			return ((sign == 1) ? (-1) : (0));
	}
	return (sign * nb);
}
