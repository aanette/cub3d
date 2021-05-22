/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:38:35 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 00:30:00 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calc_step(t_all *all)
{
	if (all->plr->ray_dir_x < 0)
	{
		all->plr->step_x = -1;
		all->plr->side_dist_x = ((float)all->plr->pos_x
				- (float)all->plr->map_x) * all->plr->delta_distx;
	}
	else
	{
		all->plr->step_x = 1;
		all->plr->side_dist_x = ((float)all->plr->map_x + 1.0
				- all->plr->pos_x) * all->plr->delta_distx;
	}
	if (all->plr->ray_dir_y < 0)
	{
		all->plr->step_y = -1;
		all->plr->side_dist_y = ((float)all->plr->pos_y
				- (float)all->plr->map_y) * all->plr->delta_disty;
	}
	else
	{
		all->plr->step_y = 1;
		all->plr->side_dist_y = ((float)all->plr->map_y
				+ 1.0 - all->plr->pos_y) * all->plr->delta_disty;
	}
}

void	find_drawstart_end(t_all *all)
{
	all->plr->height = (int)((float)all->rash->r2 /all->plr->pwd);
	all->plr->drawstart = -all->plr->height / 2 + all->rash->r2 / 2;
	if (all->plr->drawstart < 0)
		all->plr->drawstart = 0;
	all->plr->drawend = all->plr->height / 2 + all->rash->r2 / 2;
	if (all->plr->drawend >= all->rash->r2)
		all->plr->drawend = all->rash->r2 - 1;
}

void	fisheye(t_all *all)
{
	if (all->plr->side == 0)
		all->plr->pwd = (all->plr->map_x - all->plr->pos_x
				+ (1 - all->plr->step_x) / 2) / all->plr->ray_dir_x;
	else
		all->plr->pwd = (all->plr->map_y - all->plr->pos_y
				+ (1 - all->plr->step_y) / 2) / all->plr->ray_dir_y;
}

void	dda(t_all *all)
{
	all->plr->hit = 0;
	while (all->plr->hit == 0)
	{
		if (all->plr->side_dist_x < all->plr->side_dist_y)
		{
			all->plr->side_dist_x += all->plr->delta_distx;
			all->plr->map_x += all->plr->step_x;
			all->plr->side = 0;
		}
		else
		{
			all->plr->side_dist_y += all->plr->delta_disty;
			all->plr->map_y += all->plr->step_y;
			all->plr->side = 1;
		}
		if (all->map[(all->plr->map_y)][(all->plr->map_x)] == '1')
			all->plr->hit = 1;
	}
}

void	find_texture(t_all *all)
{
	all->text->texnum = 0;
	if (all->plr->side == 0)
	{
		all->text->texnum = 2;
		if (all->plr->ray_dir_x > 0)
			all->text->texnum = 3;
		all->text->wallx = all->plr->pos_y
			+ all->plr->pwd * all->plr->ray_dir_y;
	}
	else
	{
		all->text->texnum = 1;
		if (all->plr->ray_dir_y > 0)
			all->text->texnum = 0;
		all->text->wallx = all->plr->pos_x
			+ all->plr->pwd * all->plr->ray_dir_x;
	}
	all->text->wallx -= floor((all->text->wallx));
}
