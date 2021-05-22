/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:00:21 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 03:14:16 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_symb(t_all *all, int i, int j)
{
	if (all->map[i][j] == '0' || all->map[i][j] == '2'
		|| all->map[i][j] == 'N' || all->map[i][j] == 'S'
		|| all->map[i][j] == 'W' || all->map[i][j] == 'E')
		err3();
}

void	check_kray1(t_all *all, int i)
{
	int	j;

	j = 1;
	while (j < (int)ft_strlen(all->map[i]))
	{
		check_symb(all, i, j);
		if (!ft_strchr(all->map[i], '1'))
			err3();
		else if (all->map[i][j] == ' ')
		{
			if ((all->map[i][j + 1] != ' ' && all->map[i][j + 1] != '1')
			|| (all->map[i][j - 1] != ' ' && all->map[i][j - 1] != '1')
			|| (all->map[i + 1][j] != ' ' && all->map[i + 1][j] != '1'))
				err3();
		}
		j++;
	}
}

void	check_kray2(t_all *all, int i)
{
	int	j;

	j = 1;
	while (j < (int)ft_strlen(all->map[i]))
	{
		if (!ft_strchr(all->map[i], '1'))
			err3();
		else if (all->map[i][j] == ' ')
		{
			if ((all->map[i][j + 1] != ' ' && all->map[i][j + 1] != '1')
			|| (all->map[i][j - 1] != ' ' && all->map[i][j - 1] != '1')
			|| (all->map[i - 1][j] != ' ' && all->map[i - 1][j] != '1'))
				err3();
		}
		j++;
	}
}

void	check_kray3(t_all *all, int i)
{
	int	j;

	while (i < all->rash->endmap)
	{
		j = 0;
		check_symb(all, i, j);
		while (all->map[i][j] != '\0')
		{
			while (all->map[i][j] == ' ')
			{
				if (all->map[i][j] == ' ')
					j++;
				else if (all->map[i][j] == '1')
					break ;
				else
					err3();
			}
			if (all->map[i][j] == '1')
				break ;
		}
		i++;
	}
}

void	check_kray4(t_all *all, int i)
{
	int	j;

	while (i <= all->rash->endmap)
	{
		j = ft_strlen(all->map[i]) - 1;
		check_symb(all, i, j);
		while (j > 0)
		{
			while (all->map[i][j] == ' ')
				j--;
			if (all->map[i][j] == '1')
				break ;
			else
				err3();
			if (all->map[i][j] == '1')
				break ;
		}
		i++;
	}
}
