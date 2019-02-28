/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:32:23 by wned              #+#    #+#             */
/*   Updated: 2018/11/29 21:17:13 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_len(char const *s, char c)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int		word_count(char const *s, char c)
{
	int i;
	int word;
	int	label;

	if (!s)
		return (0);
	i = 0;
	word = 0;
	label = 0;
	while (s[i])
	{
		if (s[i] != c && label == 0)
		{
			label = 1;
			word++;
		}
		else if (s[i] == c && label == 1)
			label = 0;
		i++;
	}
	return (word);
}

static char		*create_word(char const *s, int len)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	if (!(str = (char *)malloc(sizeof(str) * (len + 1))))
		return (NULL);
	while (len--)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		j;

	if (!(new = (char **)malloc(sizeof(s) * (word_count(s, c) + 1))))
		return (NULL);
	j = 0;
	while (word_count(s, c) > 0)
	{
		while (*s == c && *s)
			s++;
		new[j++] = create_word(s, word_len(s, c));
		if (!new[j - 1])
		{
			while (j - 2 >= 0)
				free(new[j]);
			free(new);
			return (NULL);
		}
		s += word_len(s, c);
		while (*s == c && *s)
			s++;
	}
	new[j] = 0;
	return (new);
}
