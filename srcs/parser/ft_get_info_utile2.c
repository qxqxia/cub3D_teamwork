/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info_utile2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:53:09 by qxia              #+#    #+#             */
/*   Updated: 2022/09/16 11:55:45 by qxia             ###   ########.fr       */
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
