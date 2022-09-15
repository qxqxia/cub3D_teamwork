/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:41:48 by qxia              #+#    #+#             */
/*   Updated: 2022/09/15 16:15:32 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_put_info(t_cub3d **cub3d, char **info_array)
{
	if (ft_init_info(cub3d))
	{
		ft_free_strarray(info_array);
		return (ERR_INFO);
	}
	if (ft_put_info_in_cub3d(info_array, (*cub3d)->info))
	{
		ft_free_strarray(info_array);
		return (ERR_INFO);
	}
	return (0);
}

int	ft_get_info(int fd, t_cub3d **cub3d)
{
	char	*line;
	int		index;
	char	**info_array;

	info_array = malloc(sizeof(char *) * 7);
	if (!info_array)
		return (ERR_MALLOC);
	index = 0;
	while (get_next_line(fd, &line) > 0 && index < 6)
	{
		if (line && line[0] != '\0')
		{
			info_array[index] = line;
			index++;
		}
		else if (line)
			free(line);
	}
	if (line)
		free(line);
	info_array[index] = NULL;
	if (ft_put_info(cub3d, info_array))
		return (ERR_INFO);
	ft_free_strarray(info_array);
	return (ft_check_info((*cub3d)->info));
}
