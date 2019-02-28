/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:18:31 by wned              #+#    #+#             */
/*   Updated: 2018/11/27 12:38:45 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*new;
	char	*new_begin;

	new = (char *)malloc(sizeof(char) * size);
	new_begin = new;
	if (new == NULL)
		return (NULL);
	while (size--)
	{
		*new = 0;
		new++;
	}
	return ((void *)new_begin);
}
