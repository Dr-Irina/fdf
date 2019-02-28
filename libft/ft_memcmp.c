/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:07:52 by wned              #+#    #+#             */
/*   Updated: 2018/11/26 16:48:11 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			i;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (n--)
	{
		if (*(s11 + i) != *(s22 + i))
			return (*(s11 + i) - *(s22 + i));
		i++;
	}
	if (!s1 && !s2 && !n)
		return (0);
	return (0);
}
