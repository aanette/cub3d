/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:44:50 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 01:19:24 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_n(t_all *all, int i, int j)
{
	all->plr->x = j + 0.5;
	all->plr->y = i + 0.5;
	all->plr->dir_x = 0;
	all->plr->dir_y = -1;
	all->plr->x_plane = 0.66;
	all->plr->y_plane = 0;
	all->rash->pov = 1;
}

void	init_s(t_all *all, int i, int j)
{
	all->plr->x = j + 0.5;
	all->plr->y = i + 0.5;
	all->plr->dir_x = 0;
	all->plr->dir_y = 1;
	all->plr->x_plane = -0.66;
	all->plr->y_plane = 0;
	all->rash->pov = -1;
}

void	init_w(t_all *all, int i, int j)
{
	all->plr->x = j + 0.5;
	all->plr->y = i + 0.5;
	all->plr->dir_x = -1;
	all->plr->dir_y = 0;
	all->plr->x_plane = 0;
	all->plr->y_plane = -0.66;
	all->rash->pov = -1;
}

void	init_e(t_all *all, int i, int j)
{
	all->plr->x = j + 0.5;
	all->plr->y = i + 0.5;
	all->plr->dir_x = 1;
	all->plr->dir_y = 0;
	all->plr->x_plane = 0;
	all->plr->y_plane = 0.66;
	all->rash->pov = 1;
}

void	init(t_all *all)
{
	all->plr->pos_x = all->plr->x;
	all->plr->pos_y = all->plr->y;
	all->plr->movespeed = 0.60;
	all->plr->rotspeed = 0.10;
	all->text->texwe = 64;
	all->text->texhi = 64;
}
