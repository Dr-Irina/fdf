/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrice <hrice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:49:10 by hrice             #+#    #+#             */
/*   Updated: 2019/03/02 17:30:59 by hrice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						read_file(t_new_l *line, char *buff)
{
	int		ret;
	char	*str;

	if (!(line->str))
		line->str = ft_strnew(0);
	while ((ret = read(line->file, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(line->str, buff);
		ft_strdel(&(line->str));
		line->str = str;
		if (ft_strchr(buff, '\n'))
			return (1);
	}
	if (ret == 0 && line->str[0])
		return (1);
	return (ret);
}

void					fin(t_new_l *newl, char **line)
{
	char	*strbuff;
	char	*strmem;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (newl->str[i] && newl->str[i] != '\n')
		i++;
	if (!(strbuff = ft_strnew(i)))
		return ;
	ft_strncpy(strbuff, newl->str, i);
	if (newl->str[i] == '\n')
		i++;
	if (!(strmem = ft_strnew(ft_strlen(newl->str) - i)))
		return ;
	while (newl->str[i + j])
	{
		strmem[j] = newl->str[i + j];
		j++;
	}
	*line = strbuff;
	ft_strdel(&newl->str);
	newl->str = strmem;
}

t_new_l					*list(t_new_l **lst, int fd)
{
	t_new_l		*node;
	t_new_l		*prev;

	if (fd < 0)
		return (NULL);
	node = *lst;
	prev = NULL;
	while (node)
	{
		if (node->file == fd)
			return (node);
		prev = node;
		node = node->next;
	}
	if (!(node = (t_new_l*)malloc(sizeof(t_new_l))))
		return (NULL);
	node->file = fd;
	node->next = NULL;
	node->str = NULL;
	if (prev == NULL)
		*lst = node;
	else
		prev->next = node;
	return (node);
}

int						get_next_line(int const fd, char **line)
{
	static t_new_l		*newl;
	t_new_l				*node;
	int					ret;
	char				*buff;

	if (!line || fd < 0 || !(node = list(&newl, fd)))
		return (-1);
	buff = ft_memalloc(BUFF_SIZE + 1);
	if ((ret = read_file(node, buff)) > 0)
		fin(node, line);
	free(buff);
	return (ret);
}
