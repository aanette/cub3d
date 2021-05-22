/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:43:09 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 00:38:31 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw2(t_all *all, int x, int y1, int y2)

{
	int	y;
	int	color2;

	y = y1;
	color2 = create_trgb(0, all->rash->f1, all->rash->f2, all->rash->f3);
	while (y <= y2)
	{
		my_mlx_pixel_put(all, x, y, color2);
		y++;
	}
}

void	inittextvalue(t_all *all)
{
	all->text->texx = (int)(all->text->wallx * (float)all->text->texwe);
	if ((all->plr->side == 0) && (all->plr->ray_dir_x > 0))
		all->text->texx = all->text->texwe - all->text->texx - 1;
	if ((all->plr->side == 0) && (all->plr->ray_dir_y < 0))
		all->text->texx = all->text->texwe - all->text->texx - 1;
	all->text->step = 1.0 * all->text->texhi / all->plr->height;
	all->text->texpos = (all->plr->drawstart - all->rash->r2 / 2
			+ all->plr->height / 2) * all->text->step;
}

int	mainloop(t_all *all)
{
	colona(all);
	return (1);
}

void	all_funk(t_all *all)
{
	calc_step(all);
	dda(all);
	fisheye(all);
	find_drawstart_end(all);
	find_texture(all);
	inittextvalue(all);
}

void	colona(t_all *all)
{
	int	x;

	x = 0;
	while (x < all->rash->r1)
	{
		all->plr->camera_x = 2 * x / (float) all->rash->r1 - 1;
		all->plr->ray_dir_x = all->plr->dir_x
			+ all->plr->x_plane * all->plr->camera_x;
		all->plr->ray_dir_y = all->plr->dir_y
			+ all->plr->y_plane * all->plr->camera_x;
		all->plr->map_x = (int)all->plr->pos_x;
		all->plr->map_y = (int)all->plr->pos_y;
		all->plr->delta_distx = fabs(1 / all->plr->ray_dir_x);
		all->plr->delta_disty = fabs(1 / all->plr->ray_dir_y);
		all_funk(all);
		draw_all_tex1(all, x);
		all->spr->zbuf[x] = all->plr->pwd;
		x++;
	}
	poehali(all);
	if (all->rash->flag == 1)
		create_screenshot(all);
	mlx_put_image_to_window(all->vars->mlx, all->vars->win,
		all->img->img, 0, 0);
	mlx_do_sync(all->vars->mlx);
}
