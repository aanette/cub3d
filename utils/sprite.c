/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 01:25:55 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 01:13:21 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_sprite_size(t_all *all)
{
	all->spr->spriteh = abs((int)(all->rash->r2 / all->spr->transy));
	all->spr->drawstarty = -all->spr->spriteh / 2 + all->rash->r2 / 2;
	if (all->spr->drawstarty < 0)
		all->spr->drawstarty = 0;
	all->spr->drawendy = all->spr->spriteh / 2 + all->rash->r2 / 2;
	if (all->spr->drawendy >= all->rash->r2)
		all->spr->drawendy = all->rash->r2 - 1;
	all->spr->spritew = abs((int)(all->rash->r2 / all->spr->transy));
	all->spr->drawstartx = -all->spr->spritew / 2 + all->spr->spritescreenx;
	if (all->spr->drawstartx < 0)
		all->spr->drawstartx = 0;
	all->spr->drawendx = all->spr->spritew / 2 + all->spr->spritescreenx;
	if (all->spr->drawendx >= all->rash->r1)
		all->spr->drawendx = all->rash->r1 - 1;
}

void	transformation(t_all *all)
{
	all->spr->invdet = 1.0 / (all->plr->x_plane * all->plr->dir_y
			- all->plr->dir_x * all->plr->y_plane);
	all->spr->transx = all->spr->invdet * (all->plr->dir_y * all->spr->sprx
			- all->plr->dir_x * all->spr->spry);
	all->spr->transy = all->spr->invdet * (-all->plr->y_plane * all->spr->sprx
			+ all->plr->x_plane * all->spr->spry);
	all->spr->spritescreenx = (int)((all->rash->r1 / 2)
			* (1 + all->spr->transx / all->spr->transy));
	check_sprite_size(all);
}

void	draw_sprite(t_all *all)
{
	int	k;

	k = all->spr->drawstartx;
	while (k < all->spr->drawendx)
	{
		all->spr->texx = (int)((256 * (k
						- (-all->spr->spritew / 2 + all->spr->spritescreenx))
					* all->text->texwe / all->spr->spritew) / 256);
		if ((all->spr->transy > 0) && (k > 0) && (k < all->rash->r1)
			&& (all->spr->transy < all->spr->zbuf[k]))
			colorcheker(all, k);
		k++;
	}
}

void	poehali(t_all *all)
{
	int	i;

	i = 0;
	while (i != all->spr->spritenum)
	{
		all->spr->sprx = all->spr->sprite_x[all->spr->spriteord[i]]
			- all->plr->pos_x;
		all->spr->spry = all->spr->sprite_y[all->spr->spriteord[i]]
			- all->plr->pos_y;
		transformation(all);
		draw_sprite(all);
		i++;
	}
}

int	ft_sprite_dist(t_all *all)
{
	float	i;
	float	j;
	int		k;

	k = 0;
	while (k != all->spr->spritenum)
	{
		all->spr->spriteord[k] = k;
		i = (all->plr->pos_x - all->spr->sprite_x[k]);
		j = (all->plr->pos_y - all->spr->sprite_y[k]);
		all->spr->spritedist[k] = i * i + j * j;
		k++;
	}
	sort_sprite(all->spr->spriteord, all->spr->spritedist, all->spr->spritenum);
	return (0);
}
