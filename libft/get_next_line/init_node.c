/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:32:33 by qxia              #+#    #+#             */
/*   Updated: 2022/09/09 11:32:35 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"

void	init_node(t_list *node, int fd)
{
	node = (t_list *)malloc(sizeof(t_list) * 1);
	if (!node)
		return ;
	node->fd = fd;
	node->next = NULL;
	node->cont = (char *)malloc(sizeof(char) * 1);
	if (!node->cont)
		return ;
	(node->cont)[0] = '\0';
}
