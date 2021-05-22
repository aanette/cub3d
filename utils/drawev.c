/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:45:07 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 00:22:37 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_tex(t_all *all)
{
	load_image_no(all, &all->text->tex[0], all->rash->no);
	load_image_so(all, &all->text->tex[1], all->rash->so);
	load_image_ea(all, &all->text->tex[2], all->rash->ea);
	load_image_we(all, &all->text->tex[3], all->rash->we);
	load_image_sp(all, &all->text->tex[4], all->rash->s);
}

void	drawtexture(t_all *all, int x)
{
	int	y;
	int	k;

	y = all->plr->drawstart;
	while (y < all->plr->drawend)
	{
		all->text->texy = (int)all->text->texpos & (all->text->texhi - 1);
		all->text->texpos += all->text->step;
		k = all->text->texhi * all->text->texy + all->text->texx;
		all->text->color = all->text->tex[all->text->texnum][k];
		my_mlx_pixel_put(all, x, y, all->text->color);
		y++;
	}
}

void	draw1(t_all *all, int x, int y1, int y2)

{
	int	y;
	int	color1;

	y = y1;
	color1 = create_trgb(0, all->rash->c1, all->rash->c2, all->rash->c3);
	while (y <= y2)
	{
		my_mlx_pixel_put(all, x, y, color1);
		y++;
	}
}

void	draw_all_tex1(t_all *all, int x)
{
	draw1(all, x, 0, all->plr->drawstart);
	drawtexture(all, x);
	draw2(all, x, all->plr->drawend, all->rash->r2);
}

void	colorcheker(t_all *all, int x)
{
	int	y;
	int	d;
	int	color;
	int	j;

	y = all->spr->drawstarty;
	while (y < all->spr->drawendy)
	{
		d = y * 256 - all->rash->r2 * 128 + all->spr->spriteh * 128;
		all->spr->texy = ((d * all->text->texhi) / all->spr->spriteh / 256);
		j = (all->text->texwe * all->spr->texy + all->spr->texx);
		color = all->text->tex[4][j];
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(all, x, y, color);
		y++;
	}
}
