/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:47:23 by qxia              #+#    #+#             */
/*   Updated: 2022/09/09 14:33:18 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_dir_img(t_cub3d *cub, t_img_set *images)
{
	if (images->no.img)
		mlx_destroy_image(cub->mlx, images->no.img);
	if (images->so.img)
		mlx_destroy_image(cub->mlx, images->so.img);
	if (images->we.img)
		mlx_destroy_image(cub->mlx, images->we.img);
	if (images->ea.img)
		mlx_destroy_image(cub->mlx, images->ea.img);
}

void	free_smallmap_imgs(t_cub3d *cub, t_img_set *imgs)
{
	if (imgs->plr)
	{
		mlx_destroy_image(cub->mlx, imgs->plr->img);
		free(imgs->plr);
	}
	if (imgs->smallmap)
	{
		mlx_destroy_image(cub->mlx, imgs->smallmap->img);
		free(imgs->smallmap);
	}
	if (imgs->dir)
	{
		mlx_destroy_image(cub->mlx, imgs->dir->img);
		free(imgs->dir);
	}
	if (imgs->flr)
	{
		mlx_destroy_image(cub->mlx, imgs->flr->img);
		free(imgs->flr);
	}
	return ;
}

void	ft_free_images(t_cub3d *cub, t_img_set *imgs)
{
	if (!imgs)
		return ;
	if (imgs->graphic)
	{
		mlx_destroy_image(cub->mlx, imgs->graphic->img);
		free(imgs->graphic);
	}
	free_smallmap_imgs(cub, imgs);
	free_dir_img(cub, imgs);
	free(imgs);
	return ;
}

void	ft_free_info(t_info *info)
{
	if (info)
	{
		if (info->no)
			free(info->no);
		if (info->so)
			free(info->so);
		if (info->we)
			free(info->we);
		if (info->ea)
			free(info->ea);
		if (info->c)
			free(info->c);
		if (info->f)
			free(info->f);
		free(info);
	}
	return ;
}

void	ft_free_cub3d(t_cub3d *cub3d)
{
	if (cub3d)
	{
		if (cub3d->map)
			ft_free_strarray(cub3d->map);
		ft_free_info(cub3d->info);
		if (cub3d->plr)
			free(cub3d->plr);
		ft_free_images(cub3d, cub3d->imgs);
		if (cub3d->win)
			mlx_destroy_window(cub3d->mlx, cub3d->win);
		if (cub3d->mlx)
		{
			mlx_destroy_display(cub3d->mlx);
			free(cub3d->mlx);
		}
		free(cub3d);
	}
	return ;
}
