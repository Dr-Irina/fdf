/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_digit_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:59:35 by hrice             #+#    #+#             */
/*   Updated: 2019/03/05 19:06:56 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_digit_base(char c, int base)
{
	const char	*digits = "0123456789ABCDEF";
	int	i;

	i = 0;
	printf("CHECKING: C= %c\n", c);
	while (i < base)
	{
		printf("DIGIT_BASE: %d, %c, %c\n", i, digits[i], ft_toupper(c));
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	/* printf("DIGIT_BASE: %d, %c\n", i, digits[i]); */
	return (-1);
}
