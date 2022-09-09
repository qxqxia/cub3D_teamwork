/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:32:16 by qxia              #+#    #+#             */
/*   Updated: 2022/09/09 11:32:18 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_the_line(char **line, char **cont)
{
	int		index;
	int		nl_index;
	char	*the_line;

	index = 0;
	the_line = NULL;
	nl_index = find_n(*cont);
	if (nl_index == -1)
		nl_index = ft_strlen(*cont);
	if (nl_index >= 0)
		the_line = (char *)malloc(sizeof(char) * (nl_index + 1));
	if (!the_line)
		return (0);
	while (index < nl_index)
	{
		the_line[index] = (*cont)[index];
		index++;
	}
	the_line[index] = '\0';
	*line = the_line;
	return (1);
}

int	read_fd(int fd, t_list *fd_node)
{
	int				ret;
	char			*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < 0)
		return (ret);
	while (ret > 0)
	{
		buf[ret] = '\0';
		join_and_free(buf, &(fd_node->cont));
		if (find_n(fd_node->cont) != -1)
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*static_list;
	t_list			*fd_node;
	int				ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	fd_node = get_node(fd, &static_list);
	ret = read_fd(fd, fd_node);
	if (ret == -1)
		return (-1);
	get_the_line(line, &(fd_node->cont));
	update_cont(&(fd_node->cont));
	if (ret == 0 && !fd_node->cont)
	{
		delete_node(fd, &static_list);
		return (0);
	}
	return (1);
}
