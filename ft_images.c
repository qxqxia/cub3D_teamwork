/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:11:24 by qxia              #+#    #+#             */
/*   Updated: 2022/09/02 10:15:50 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_imgs(t_cub3d *cub)
{
	cub->imgs->no.img = mlx_xpm_file_to_image(cub->mlx, \
		cub->info->no, &cub->imgs->no.w, &cub->imgs->no.h);
	cub->imgs->so.img = mlx_xpm_file_to_image(cub->mlx, \
		cub->info->so, &cub->imgs->so.w, &cub->imgs->so.h);
	cub->imgs->we.img = mlx_xpm_file_to_image(cub->mlx, \
		cub->info->we, &cub->imgs->we.w, &cub->imgs->we.h);
	cub->imgs->ea.img = mlx_xpm_file_to_image(cub->mlx, \
		cub->info->ea, &cub->imgs->ea.w, &cub->imgs->ea.h);
	if (!cub->imgs->no.img || !cub->imgs->so.img || \
		!cub->imgs->we.img || !cub->imgs->ea.img)
		return (1);
	cub->imgs->no.addr = mlx_get_data_addr(cub->imgs->no.img, \
		&cub->imgs->no.bpp, &cub->imgs->no.size, &cub->imgs->no.endian);
	cub->imgs->so.addr = mlx_get_data_addr(cub->imgs->so.img, \
		&cub->imgs->so.bpp, &cub->imgs->so.size, &cub->imgs->so.endian);
	cub->imgs->we.addr = mlx_get_data_addr(cub->imgs->we.img, \
		&cub->imgs->we.bpp, &cub->imgs->we.size, &cub->imgs->we.endian);
	cub->imgs->ea.addr = mlx_get_data_addr(cub->imgs->ea.img, \
		&cub->imgs->ea.bpp, &cub->imgs->ea.size, &cub->imgs->ea.endian);
	if (!cub->imgs->no.addr || !cub->imgs->so.addr || \
		!cub->imgs->we.addr || !cub->imgs->ea.addr)
		return (1);
	return (0);
}