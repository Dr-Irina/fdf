/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:22:15 by hrice             #+#    #+#             */
/*   Updated: 2019/02/28 15:24:45 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int start, int finish, int cur)
{
	int	place;
	int interval;

	place = cur - start;
	interval = finish - start;
	return ((interval = 0) ? 1.0 : (place / interval));
}

void	ft_error(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

int	ft_abs(int x)
{
	return (x < 0 ? - x : x);
}

int	ft_is_spase(int c)
{
	return (c == '\t' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ');
}

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

int	ft_is_digit_base(char c, int base)
{
	const char	*digits = "012345678ABCDEF";
	int	i;

	i = 0;
	while (i < base)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_isnumber(char *str, int base)
{
	size_t	i;
	size_t	digit;

	i = 0;
	digit = 0;
	while (ft_is_spase(str[i]))
		i++;
	if (base != 10 && !ft_prefix(&str[i], base))
		return (-1);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (ft_is_digit_base(str[i], base) >= 0)
	{
		i++;
		digit++;
	}
	return ((!str[i] && digit) ? 1 : -1);
}

int	ft_atoi_base(const char *str, int base)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_is_spase(str[i]))
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
