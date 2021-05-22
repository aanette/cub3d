/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:50:35 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 01:08:48 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_player(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	all->plr->dist = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (init_ev(all, i, j) == 1)
				return ;
			j++;
		}
		i++;
	}
}

int	init_ev(t_all *all, int i, int j)
{
	if (all->map[i][j] == 'S')
	{
		init_s(all, i, j);
		return (1);
	}
	if (all->map[i][j] == 'N')
	{
		init_n(all, i, j);
		return (1);
	}
	if (all->map[i][j] == 'W')
	{
		init_w(all, i, j);
		return (1);
	}
	if (all->map[i][j] == 'E')
	{
		init_e(all, i, j);
		return (1);
	}
	return (0);
}
