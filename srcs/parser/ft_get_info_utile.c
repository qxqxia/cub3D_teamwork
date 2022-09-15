/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info_utile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:41:48 by qxia              #+#    #+#             */
/*   Updated: 2022/09/15 16:15:32 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	*ft_get_colors_lp(char	**holder, int *colors, int	*colors_i)
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
}

int	ft_check_struct(char **dir_img, char **line)
{
	if (*dir_img)
	{
		ft_free_strarray(line);
		return (1);
	}
	if (line[1])
	{
		*dir_img = ft_strdup(line[1]);
		ft_free_strarray(line);
	}
	if (!*dir_img || !(*dir_img)[0])
		return (1);
	return (0);
}

int	ft_check_struct_colors(int	**cf_img, char **line)
{
	if (*cf_img)
	{
		ft_free_strarray(line);
		return (1);
	}
	if (line[1])
	{
		*cf_img = ft_get_colors(line);
		ft_free_strarray(line);
		if (!*cf_img)
			return (1);
	}
	return (0);
}

int	ft_put_info_in_cub3d(char **info_array, t_info *info_struct)
{
	char	**line;
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	while (info_array[++i])
	{
		line = ft_split(info_array[i], ' ');
		if (ft_strcmp(line[0], "NO") == 0)
			ret = ft_check_struct(&(info_struct->no), line);
		else if (ft_strcmp(line[0], "SO") == 0)
			ret = ft_check_struct(&(info_struct->so), line);
		else if (ft_strcmp(line[0], "WE") == 0 && line[1])
			ret = ft_check_struct(&(info_struct->we), line);
		else if (ft_strcmp(line[0], "EA") == 0)
			ret = ft_check_struct(&(info_struct->ea), line);
		else if (ft_strcmp(line[0], "C") == 0)
			ret = ft_check_struct_colors(&(info_struct->c), line);
		else if (ft_strcmp(line[0], "F") == 0)
			ret = ft_check_struct_colors(&(info_struct->f), line);
		if (ret == 1)
			return (1);
	}
	return (0);
}
