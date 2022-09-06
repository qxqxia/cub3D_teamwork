/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_smallmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:30:12 by qxia              #+#    #+#             */
/*   Updated: 2022/09/06 15:39:30 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*ft_create_tile(t_cub3d *cub3d, unsigned int color, int size)
{
	t_img	*img_buffer;
	int			i;
	int			j;
	char		*pixel;

	img_buffer = malloc(sizeof(t_img));
	img_buffer->img = mlx_new_image(cub3d->mlx, size, size);
	img_buffer->addr = mlx_get_data_addr(img_buffer->img, \
		&(img_buffer->bpp), &(img_buffer->size), &(img_buffer->endian));
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			pixel = img_buffer->addr + \
				(i * img_buffer->size) + j * (img_buffer->bpp / 8);
			ft_memcpy(pixel, &color, sizeof(unsigned int));
			j++;
		}
		i++;
	}
	return (img_buffer);
}

void	ft_smallmap_lp(t_cub3d *cub, t_img *map, t_img *floor, int i)
{
	int	j;

	j = -1;
	while (++j < (int)ft_strlen((cub->map)[i]))
	{
		if (cub->map[i][j] == '1')
		{
			mlx_put_image_to_window(cub->mlx, cub->win, map->img, \
				j * 10 + 20, i * 10 + 20);
		}
		if (cub->map[i][j] == '0' || cub->map[i][j] == 'W' || \
			cub->map[i][j] == 'E' || cub->map[i][j] == 'N' || \
			cub->map[i][j] == 'S')
		{
			mlx_put_image_to_window(cub->mlx, cub->win, floor->img, \
				j * 10 + 20, i * 10 + 20);
		}
	}
}

int	ft_print_smallmap(t_cub3d *cub, t_img_set *ig)
{
	int			i;

	if (!ig->smallmap)
		ig->smallmap = ft_create_tile(cub, 0x00AAAAAA, 10);
	if (!ig->plr)
		ig->plr = ft_create_tile(cub, 0x009F0000, 5);
	if (!ig->dir)
		ig->dir = ft_create_tile(cub, 0x009F00FF, 5);
	if (!ig->flr)
		ig->flr = ft_create_tile(cub, 0x00000000, 10);
	i = 0;
	while (i < ft_arraylen(cub->map))
	{
		ft_smallmap_lp(cub, ig->smallmap, ig->flr, i);
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, ig->plr->img, \
		cub->plr->p_y * 10 + 20 - 2, cub->plr->p_x * 10 + 20 - 2);
	mlx_put_image_to_window(cub->mlx, cub->win, ig->dir->img, \
		(cub->plr->p_y + cub->plr->d_y) * 10 + 20 - 2, \
		(cub->plr->p_x + cub->plr->d_x) * 10 + 20 - 2);
	return (0);
}
