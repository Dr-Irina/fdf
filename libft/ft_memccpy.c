/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:29:03 by wned              #+#    #+#             */
/*   Updated: 2018/11/26 20:15:26 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	while (n--)
	{
		*s1 = *s2;
		if (*s2 == (char)c)
			return (s1 + 1);
		s1++;
		s2++;
	}
	return (NULL);
}
