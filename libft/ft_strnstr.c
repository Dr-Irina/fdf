/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:16:41 by wned              #+#    #+#             */
/*   Updated: 2018/11/23 11:29:21 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;

	if (!*little)
		return ((char *)big);
	while (*big && len)
	{
		i = 0;
		while (big[i] == little[i] && len - i)
		{
			if (little[i + 1] == '\0')
				return ((char *)big);
			i++;
		}
		big++;
		len--;
	}
	return (NULL);
}
