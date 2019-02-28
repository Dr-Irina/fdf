/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:52:18 by wned              #+#    #+#             */
/*   Updated: 2018/12/01 13:34:07 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		slen;
	size_t		dlen;

	dlen = 0;
	slen = ft_strlen(src);
	while (*dst && size)
	{
		dst++;
		size--;
		dlen++;
	}
	while (*src && size > 1)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
		if (size == 1 || !*src)
			*dst = '\0';
	}
	return (slen + dlen);
}
