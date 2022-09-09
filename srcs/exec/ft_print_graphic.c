/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_graphic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:44:40 by qxia              #+#    #+#             */
/*   Updated: 2022/09/06 16:19:54 by qxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_delta_dist(t_cub3d *cub, double x, t_ray *ray)
{
	double	camera_x;

	camera_x = 2 * x / 1240 - 1;
	ray->dir_x = cub->plr->d_x + cub->plr->pl_x * camera_x;
	ray->dir_y = cub->plr->d_y + cub->plr->pl_y * camera_x;
	ray->delta_dist_x = 1000000;
	ray->delta_dist_y = 1000000;
	if (ray->dir_x != 0)
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y != 0)
		ray->delta_dist_y = fabs(1 / ray->dir_y);
}

void	calcu_texture(t_cub3d *cub, t_ray *ray, t_text *tex, t_img *texture)
{
	if (ray->side == 0)
		ray->wall_x = cub->plr->p_y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = cub->plr->p_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor((ray->wall_x));
	tex->start = -ray->lign_h / 2 + 720 / 2;
	if (tex->start < 0)
		tex->start = 0;
	tex->end = ray->lign_h / 2 + 720 / 2;
	if (tex->end >= 720)
		tex->end = 720 - 1;
	tex->tex_x = (int)(ray->wall_x * (double)(texture->w));
	if ((ray->side == 0 && ray->dir_x > 0) || \
		(ray->side == 1 && ray->dir_y < 0))
		tex->tex_x = texture->w - tex->tex_x - 1;
	tex->step = 1.0 * texture->h / ray->lign_h;
	tex->tex_p = (tex->start - 720 / 2 + ray->lign_h / 2) * tex->step;
}

void	print_texture(t_cub3d *cub, t_ray *ray, t_img *t_ig, t_img *c_ig)
{
	t_text	tex;
	int		y;
	char	*pixel;
	int		tex_y;
	int		color;

	calcu_texture(cub, ray, &tex, t_ig);
	y = 0;
	while (y < 720)
	{
		if (y < tex.start)
			color = rgb_to_int(cub->info->c);
		else if (y > tex.end)
			color = rgb_to_int(cub->info->f);
		else
		{
			tex_y = (int)tex.tex_p & (t_ig->h - 1);
			color = ((int *)t_ig->addr)[(256 / 4) * tex_y + tex.tex_x];
			tex.tex_p += tex.step;
		}
		pixel = c_ig->addr + ((int)(y) *c_ig->size) + \
			(int)ray->lp_x * (c_ig->bpp / 8);
		*(unsigned int *)pixel = color;
		y++;
	}
}

void	ft_init_graphic(t_cub3d *cub)
{
	cub->imgs->graphic = malloc(sizeof(t_img));
	cub->imgs->graphic->img = mlx_new_image(cub->mlx, 1240, 720);
	cub->imgs->graphic->addr = mlx_get_data_addr(cub->imgs->graphic->img, \
		&(cub->imgs->graphic->bpp), &(cub->imgs->graphic->size), \
		&(cub->imgs->graphic->endian));
	return ;
}

void	ft_print_graphic(t_cub3d *cub)
{
	double		x;
	t_img	*graphic;
	t_ray		ray;
	t_img	*texture;

	if (!(cub->imgs->graphic))
		ft_init_graphic(cub);
	graphic = cub->imgs->graphic;
	x = 0.00;
	while (x < 1240)
	{
		init_delta_dist(cub, x, &ray);
		init_side_dist(cub, &ray, (int)(cub->plr->p_x), (int)(cub->plr->p_y));
		dda(cub, &ray, (int)(cub->plr->p_x), (int)(cub->plr->p_y));
		texture = chose_texture(cub, ray);
		ray.lp_x = x;
		print_texture(cub, &ray, texture, graphic);
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, graphic->img, 0, 0);
	cub->imgs->graphic = graphic;
}
