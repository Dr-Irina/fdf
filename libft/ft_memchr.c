/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:59:27 by wned              #+#    #+#             */
/*   Updated: 2018/11/26 20:16:54 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*s1;
	size_t		i;

	s1 = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (*(s1 + i) == (char)c)
			return ((void *)(s1 + i));
		i++;
	}
	return (NULL);
}
