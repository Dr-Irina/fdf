/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:57:35 by wned              #+#    #+#             */
/*   Updated: 2018/11/29 17:05:30 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && (i != j))
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && (i != j))
		j--;
	if (i == j)
		return (ft_strnew(0));
	new = ft_strsub(s, i, j - i + 1);
	return (new);
}
