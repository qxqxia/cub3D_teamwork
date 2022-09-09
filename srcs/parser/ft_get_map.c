/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:43:00 by qxia              #+#    #+#             */
/*   Updated: 2022/09/09 10:50:19 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_arraylen(char **str_array)
{
	int	length;

	length = 0;
	if (str_array)
	{
		while (str_array[length])
			length++;
	}
	return (length);
}

void	ft_free_strarray(char **str_array)
{
	char	**holder;

	if (str_array)
	{
		holder = str_array;
		while (*holder)
		{
			free(*holder);
			holder++;
		}
		free(str_array);
	}
	return ;
}

static char	**ft_add_to_array(char **str_array, char *str)
{
	int		array_len;
	char	**new_array;
	int		index;

	array_len = ft_arraylen(str_array);
	new_array = malloc(sizeof(char *) * (array_len + 2));
	index = 0;
	while (str_array && str_array[index] && index < array_len)
	{
		new_array[index] = str_array[index];
		index++;
	}
	new_array[index] = ft_strdup(str);
	new_array[index + 1] = NULL;
	free(str_array);
	free(str);
	return (new_array);
}

int	ft_get_map(int fd, t_cub3d **cub3d)
{
	int		gnl_ret;
	char	*line;
	char	**map;

	map = NULL;
	gnl_ret = get_next_line(fd, &line);
	while (gnl_ret > 0)
	{
		if (line[0] != '\0')
			map = ft_add_to_array(map, line);
		else
			free(line);
		gnl_ret = get_next_line(fd, &line);
	}
	if (gnl_ret < 0)
		return (ERR_GNL);
	if (line)
		free(line);
	(*cub3d)->map = map;
	return (ft_check_map((*cub3d)->map));
}