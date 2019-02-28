/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:12:58 by wned              #+#    #+#             */
/*   Updated: 2018/11/27 14:48:25 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	char	*fresh_begin;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	fresh = ft_strnew(len);
	fresh_begin = fresh;
	if (fresh == NULL)
		return (NULL);
	while (*s)
	{
		*fresh = f(*s);
		s++;
		fresh++;
	}
	return (fresh_begin);
}
