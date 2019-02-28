/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:03:36 by wned              #+#    #+#             */
/*   Updated: 2018/11/23 12:11:02 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = 0;
	while (s1[len])
		len++;
	s2 = (char *)malloc(sizeof(*s2) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
