/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cub3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:47:23 by qxia              #+#    #+#             */
/*   Updated: 2022/09/05 14:02:53 by qxia             ###   ########.fr       */
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

/*void	free_minimap_imgs(t_cub3d *cub, t_images *imgs)
{
	if (imgs->plr)
	{
		mlx_destroy_image(cub->mlx_ptr, imgs->plr->img_ptr);
		free(imgs->plr);
	}
	if (imgs->minimp)
	{
		mlx_destroy_image(cub->mlx_ptr, imgs->minimp->img_ptr);
		free(imgs->minimp);
	}
	if (imgs->dir)
	{
		mlx_destroy_image(cub->mlx_ptr, imgs->dir->img_ptr);
		free(imgs->dir);
	}
	if (imgs->flr)
	{
		mlx_destroy_image(cub->mlx_ptr, imgs->flr->img_ptr);
		free(imgs->flr);
	}
	return ;
}*/

void	ft_free_images(t_cub3d *cub, t_img_set *imgs)
{
	if (!imgs)
		return ;
	/*if (imgs->canvas)
	{
		mlx_destroy_image(cub->mlx_ptr, imgs->canvas->img_ptr);
		free(imgs->canvas);
	}
	free_minimap_imgs(cub, imgs);*/
	free_dir_img(cub, imgs);
	//free(imgs);
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