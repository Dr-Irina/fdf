/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:30:44 by wned              #+#    #+#             */
/*   Updated: 2018/11/23 11:53:00 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	while (*str)
	{
		if (*str == (char)ch)
			return ((char *)str);
		str++;
	}
	if ((char)ch == '\0')
		return ((char *)str);
	return (NULL);
}
