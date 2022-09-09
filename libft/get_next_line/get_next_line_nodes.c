/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_nodes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:31:52 by qxia              #+#    #+#             */
/*   Updated: 2022/09/09 11:31:54 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	init_node(t_list *node, int fd)
{
	node->fd = fd;
	node->next = NULL;
	node->cont = (char *)malloc(sizeof(char) * 1);
	if (!(node->cont))
		return (1);
	(node->cont)[0] = '\0';
	return (0);
}

t_list	*get_node(int fd, t_list **static_list)
{
	t_list	*current_node;
	t_list	*prev_node;

	current_node = *static_list;
	prev_node = NULL;
	while (current_node)
	{
		if (current_node->fd == fd)
			return (current_node);
		prev_node = current_node;
		current_node = current_node->next;
	}
	current_node = (t_list *)malloc(sizeof(t_list) * 1);
	if (!current_node)
		return (NULL);
	if (init_node(current_node, fd) == 1)
		return (NULL);
	if (prev_node)
		prev_node->next = current_node;
	else
		*static_list = current_node;
	return (current_node);
}

int	delete_node(int fd, t_list **static_list)
{
	t_list	*current_node;
	t_list	*prev_node;

	current_node = *static_list;
	prev_node = NULL;
	while (current_node)
	{
		if (current_node->fd == fd)
		{
			if (prev_node)
				prev_node->next = current_node->next;
			else
				*static_list = current_node->next;
			free(current_node);
			return (1);
		}
		prev_node = current_node;
		current_node = current_node->next;
	}
	return (0);
}
