/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:11:16 by wned              #+#    #+#             */
/*   Updated: 2018/12/03 13:51:40 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *first;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	first = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = f(lst)))
		{
			while (first->next)
			{
				new = first->next;
				free(first);
				first = new;
			}
		}
		new = new->next;
	}
	return (first);
}
