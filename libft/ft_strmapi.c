/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:49:42 by wned              #+#    #+#             */
/*   Updated: 2018/11/27 15:00:41 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	char			*fresh_begin;
	int				len;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	fresh = ft_strnew(len);
	fresh_begin = fresh;
	if (fresh == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		*fresh = f(i, *s);
		s++;
		i++;
		fresh++;
	}
	return (fresh_begin);
}
