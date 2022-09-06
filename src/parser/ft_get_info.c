/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:41:48 by qxia              #+#    #+#             */
/*   Updated: 2022/09/06 16:27:40 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int	*ft_get_colors_lp(char	**holder, int *colors, int	*colors_i)
{
	int	j;

	j = 0;
	while (holder[j])
	{
		colors[*colors_i] = ft_atoi_unsig(holder[j]);
		if (*colors_i >= 4 || colors[*colors_i] > 255 || \
			colors[*colors_i] < 0)
		{
			ft_free_strarray(holder);
			free(colors);
			return (NULL);
		}
		(*colors_i) = (*colors_i) + 1;
		if ((*colors_i) == 4)
		{
			ft_free_strarray(holder);
			free(colors);
			return (NULL);
		}
		j++;
	}
	return (colors);
}

int	*ft_get_colors(char **line)
{
	int		i;
	int		*colors;
	int		colors_i;
	char	**holder;

	i = 0;
	colors = malloc(sizeof(int) * 3);
	colors_i = 0;
	while (line[++i])
	{
		holder = ft_split(line[i], ',');
		if ((i != 3 && line[i][ft_strlen(line[i]) - 1] != ',' && !holder[1]) || \
			!holder[0])
		{
			free(colors);
			ft_free_strarray(holder);
			return (NULL);
		}
		colors = ft_get_colors_lp(holder, colors, &colors_i);
		if (!colors)
			return (NULL);
		ft_free_strarray(holder);
	}
	return (colors);
}*/

int	ft_put_info_in_cub3d(char **info_array, t_info *info_struct)
{
	char	**line;
	int		i;

	i = -1;
	while (info_array[++i])
	{
		line = ft_split(info_array[i], ' ');
		if (ft_strcmp(line[0], "NO") == 0)
			info_struct->no = ft_strdup(line[1]);
		else if (ft_strcmp(line[0], "SO") == 0)
			info_struct->so = ft_strdup(line[1]);
		else if (ft_strcmp(line[0], "WE") == 0)
			info_struct->we = ft_strdup(line[1]);
		else if (ft_strcmp(line[0], "EA") == 0)
			info_struct->ea = ft_strdup(line[1]);
		/*else if (ft_strcmp(line[0], "C") == 0)
			info_struct->c = ft_get_colors(line);
		else if (ft_strcmp(line[0], "F") == 0)
			info_struct->f = ft_get_colors(line);
		ft_free_strarray(line);*/
	}
	/*if (!info_struct->c || !info_struct->f)
		return (1);*/
	return (0);
}

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
	while (get_next_line(fd) && index < 6)
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