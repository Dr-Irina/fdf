/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:40:23 by wned              #+#    #+#             */
/*   Updated: 2018/11/30 15:29:40 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;

	if (!(ptr = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	else
	{
		if (!(ptr->content = malloc(content_size)))
		{
			free(ptr);
			return (NULL);
		}
		ft_memcpy(ptr->content, content, content_size);
		ptr->content_size = content_size;
	}
	ptr->next = NULL;
	return (ptr);
}
