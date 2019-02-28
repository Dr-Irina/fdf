/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:34:58 by wned              #+#    #+#             */
/*   Updated: 2018/12/03 12:48:50 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*negative = 1;
		*n *= -1;
	}
}

char		*ft_itoa(int n)
{
	int		tmpn;
	int		len;
	int		negative;
	char	*new;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 1;
	tmpn = n;
	while (tmpn /= 10)
		len++;
	negative = 0;
	ft_isnegative(&n, &negative);
	len += negative;
	if ((new = ft_strnew(len)) == NULL)
		return (NULL);
	new[len] = '\0';
	while (len--)
	{
		new[len] = (n % 10) + '0';
		n /= 10;
	}
	if (negative)
		new[0] = '-';
	return (new);
}
