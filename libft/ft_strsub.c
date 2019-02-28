/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:11:15 by wned              #+#    #+#             */
/*   Updated: 2018/11/28 17:55:13 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	char	*substring_begin;
	size_t	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start > lens)
		return (NULL);
	substring = ft_strnew(len);
	substring_begin = substring;
	if (substring == NULL)
		return (NULL);
	while (len && s[start] != '\0')
	{
		*substring = s[start];
		substring++;
		start++;
		len--;
	}
	return (substring_begin);
}
