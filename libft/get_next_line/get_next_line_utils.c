/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:32:04 by qxia              #+#    #+#             */
/*   Updated: 2022/09/09 11:32:07 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_n(char *s)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

int	ft_memdel(void **ap)
{
	if (*ap)
		free(*ap);
	*ap = NULL;
	return (0);
}

int	join_and_free(char *buf, char **cont)
{
	int		index;
	int		cont_len;
	int		buf_len;
	char	*new_cont;

	index = 0;
	cont_len = ft_strlen(*cont);
	buf_len = ft_strlen(buf);
	new_cont = (char *)malloc(sizeof(char) * (cont_len + buf_len + 1));
	if (!new_cont)
		return (-1);
	while (index < (cont_len + buf_len))
	{
		if (index < cont_len)
			new_cont[index] = (*cont)[index];
		else
			new_cont[index] = buf[index - cont_len];
		index++;
	}
	new_cont[index] = '\0';
	if (*cont)
		free(*cont);
	*cont = new_cont;
	return (1);
}

int	update_cont(char **cont)
{
	int		index;
	int		nl_index;
	int		new_cont_len;
	char	*new_cont;

	if (!(*cont))
		return (ft_memdel((void **)cont));
	nl_index = find_n(*cont);
	if (nl_index == -1)
		return (ft_memdel((void **)cont));
	index = 0;
	new_cont_len = ft_strlen(*cont) - nl_index - 1;
	new_cont = (char *)malloc(sizeof(char) * (new_cont_len + 1));
	if (!new_cont)
		return (0);
	while (index < new_cont_len)
	{
		new_cont[index] = (*cont)[index + nl_index + 1];
		index++;
	}
	new_cont[index] = '\0';
	ft_memdel((void **)cont);
	*cont = new_cont;
	return (1);
}
