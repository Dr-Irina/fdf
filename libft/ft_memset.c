/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:06:08 by wned              #+#    #+#             */
/*   Updated: 2018/11/26 16:41:09 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *cp_b;

	cp_b = (unsigned char *)b;
	while (len--)
	{
		*cp_b = (unsigned char)c;
		cp_b++;
	}
	return (b);
}
