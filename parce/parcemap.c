/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:45:27 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 03:06:40 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_params(t_all *all)
{
	all->rash->err = 0;
	all->rash->begmap = 0;
	all->rash->ea = NULL;
	all->rash->so = NULL;
	all->rash->no = NULL;
	all->rash->we = NULL;
	all->rash->s = NULL;
	all->rash->r1 = -1;
	all->rash->r2 = -1;
	all->rash->c1 = -1;
	all->rash->c2 = -1;
	all->rash->c3 = -1;
	all->rash->f1 = -1;
	all->rash->f2 = -1;
	all->rash->f3 = -1;
	if (all->rash->flag != 1)
		all->rash->flag = -1;
}

void	check_params(t_all *all)
{
	if ((all->rash->r1 < 0) || (all->rash->r2 < 0) || (all->rash->f1 < 0) || \
	(all->rash->f2 < 0) || (all->rash->f3 < 0) || (all->rash->c1 < 0) || \
	(all->rash->c2 < 0) || (all->rash->c3 < 0) || (all->rash->c1 > 255) || \
	(all->rash->c2 > 255) || (all->rash->c3 > 255) || (all->rash->f3 > 255) || \
	(all->rash->f2 > 255) || (all->rash->f1 > 255) || (!all->rash->ea))
		err2();
	if (all->rash->r1 >= SCREEN_SIZE_W)
		all->rash->r1 = SCREEN_SIZE_W;
	if (all->rash->r2 >= SCREEN_SIZE_H)
		all->rash->r2 = SCREEN_SIZE_H;
}

int	check_pos_sprite(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	all->spr->spritenum = 0;
	while (all->map[i])
	{
		j = 0;
		while (i < all->rash->endmap && all->map[i][j])
		{
			if (all->map[i][j] == '2')
			{
				all->spr->sprite_x[all->spr->spritenum] = j + 0.5;
				all->spr->sprite_y[all->spr->spritenum] = i + 0.5;
				all->spr->spritedist[all->spr->spritenum] = 0;
				all->spr->spritenum++;
			}
			j++;
		}
		i++;
	}
	return (all->spr->spritenum);
}

int	check_num_str(t_all *all)
{
	int		fd;
	char	*line;
	int		j;

	fd = open (all->rash->map, O_RDONLY);
	j = 0;
	while ((get_next_line(fd, &line) > 0))
	{
		free(line);
		j++;
	}
	free(line);
	if (get_next_line(fd, &line) < 0)
		all->rash->err = -1;
	free(line);
	close(fd);
	return (j);
}

int	check(t_all *all)
{
	int	k;

	k = check_num_sp(all);
	if (k != 0)
	{
		all->spr->sprite_x = malloc(sizeof(float) * k + sizeof(float));
		all->spr->sprite_y = malloc(sizeof(float) * k + sizeof(float));
		all->spr->spritedist = malloc(sizeof(float) * k + sizeof(float));
		all->spr->spriteord = malloc(sizeof(int) * k + sizeof(float));
		all->spr->zbuf = malloc((sizeof(double) * (all->rash->r1)));
		check_pos_sprite(all);
	}
	else
		return (0);
	return (0);
}
