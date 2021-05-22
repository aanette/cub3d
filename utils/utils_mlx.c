/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:49:06 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 01:07:42 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	if ((y == all->rash->r2) || (x == all->rash->r1))
		return ;
	dst = NULL;
	dst = all->img->addr + (y * all->img->line_length + x
			* (all->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	move_123(t_all *all)
{
	all->plr->olddirx = all->plr->dir_x;
	all->plr->dir_x = all->plr->dir_x * cos(-all->plr->rotspeed)
		- all->plr->dir_y * sin(-all->plr->rotspeed);
	all->plr->dir_y = all->plr->olddirx * sin(-all->plr->rotspeed)
		+ all->plr->dir_y * cos(-all->plr->rotspeed);
	all->plr->oldplanex = all->plr->x_plane;
	all->plr->x_plane = all->plr->x_plane * cos(-all->plr->rotspeed)
		- all->plr->y_plane * sin(-all->plr->rotspeed);
	all->plr->y_plane = all->plr->oldplanex * sin(-all->plr->rotspeed)
		+ all->plr->y_plane * cos(-all->plr->rotspeed);
}

void 	move_124(t_all *all)
{
	all->plr->olddirx = all->plr->dir_x;
	all->plr->dir_x = all->plr->dir_x * cos(all->plr->rotspeed)
		- all->plr->dir_y * sin(all->plr->rotspeed);
	all->plr->dir_y = all->plr->olddirx * sin(all->plr->rotspeed)
		+ all->plr->dir_y * cos(all->plr->rotspeed);
	all->plr->oldplanex = all->plr->x_plane;
	all->plr->x_plane = all->plr->x_plane * cos(all->plr->rotspeed)
		- all->plr->y_plane * sin(all->plr->rotspeed);
	all->plr->y_plane = all->plr->oldplanex * sin(all->plr->rotspeed)
		+ all->plr->y_plane * cos(all->plr->rotspeed);
}

int	ft_close(int keycode, t_all *all)
{
	if (keycode == 13)
		move_w(all);
	else if (keycode == 1)
		move_s(all);
	else if (keycode == 2)
		move_d(all);
	else if (keycode == 0)
		move_a(all);
	else if ((keycode == 124) && (all->rash->pov > 0))
		move_124(all);
	else if ((keycode == 124) && (all->rash->pov < 0))
		move_123(all);
	else if ((keycode == 123) && (all->rash->pov > 0))
		move_123(all);
	else if ((keycode == 123) && (all->rash->pov < 0))
		move_124(all);
	if (keycode == 53)
		exit(0);
	return (0);
}
