/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooki.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:26:43 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 00:23:56 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_s(t_all *all)
{
	int	x;
	int	y;

	y = (int)(all->plr->pos_y);
	x = (int)(all->plr->pos_x - all->plr->dir_x * all->plr->movespeed);
	if (all->map[y][x] != '1')
		all->plr->pos_x -= all->plr->dir_x * all->plr->movespeed;
	x = (int)(all->plr->pos_x);
	y = (int)(all->plr->pos_y - all->plr->dir_y * all->plr->movespeed);
	if (all->map[y][x] != '1')
		all->plr->pos_y -= all->plr->dir_y * all->plr->movespeed;
}

void	move_w(t_all *all)
{
	int	x;
	int	y;

	y = (int)(all->plr->pos_y);
	x = (int)(all->plr->pos_x + all->plr->dir_x * all->plr->movespeed);
	if (all->map[y][x] != '1')
		all->plr->pos_x += all->plr->dir_x * all->plr->movespeed;
	x = (int)(all->plr->pos_x);
	y = (int)(all->plr->pos_y + all->plr->dir_y * all->plr->movespeed);
	if (all->map[y][x] != '1')
		all->plr->pos_y += all->plr->dir_y * all->plr->movespeed;
}

void	move_a(t_all *all)
{
	int	x;
	int	y;

	y = (int)(all->plr->pos_y);
	x = (int)(all->plr->pos_x - all->plr->x_plane * all->plr->movespeed);
	if (all->map[y][x] != '1')
		all->plr->pos_x -= all->plr->x_plane * all->plr->movespeed;
	x = (int)(all->plr->pos_x);
	y = (int)(all->plr->pos_y - all->plr->y_plane * all->plr->movespeed);
	if (all->map[y][x] != '1')
		all->plr->pos_y -= all->plr->y_plane * all->plr->movespeed;
}

void	move_d(t_all *all)
{
	int	x;
	int	y;

	y = (int)(all->plr->pos_y);
	x = (int)(all->plr->pos_x + all->plr->x_plane * all->plr->movespeed);
	if (all->map[y][x] != '1')
		all->plr->pos_x += all->plr->x_plane * all->plr->movespeed;
	x = (int)(all->plr->pos_x);
	y = (int)(all->plr->pos_y + all->plr->y_plane * all->plr->movespeed);
	if (all->map[y][x] != '1')
		all->plr->pos_y += all->plr->y_plane * all->plr->movespeed;
}
