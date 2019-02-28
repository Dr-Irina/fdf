/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:02:59 by wned              #+#    #+#             */
/*   Updated: 2018/11/27 20:25:57 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*new_begin;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new = ft_strnew(len);
	new_begin = new;
	if (!new)
		return (NULL);
	while (*s1)
		*new++ = *s1++;
	while (*s2)
		*new++ = *s2++;
	return (new_begin);
}
