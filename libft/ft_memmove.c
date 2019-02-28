/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:32:11 by wned              #+#    #+#             */
/*   Updated: 2018/11/29 14:10:47 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (src == dst)
		return (dst);
	if (s2 < s1)
		while (len)
		{
			s1[len - 1] = s2[len - 1];
			len--;
		}
	while (len--)
		*s1++ = *s2++;
	return (dst);
}
