/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcemap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:05:38 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 03:25:30 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_arg(t_all *all, char **argv)
{
	size_t	i;

	i = ft_strlen(argv[1]);
	if (i < 5)
		err2();
	if (!((argv[1][i - 1] == 'b') && (argv[1][i - 2] == 'u') \
	&& (argv[1][i - 3] == 'c') && (argv[1][i - 4] == '.')))
		err2();
	else
	{
		all->rash->map = argv[1];
	}
	if (argv[2])
		screenshot(all, argv);
}

void	parcemap(int i, int j, t_all *all)
{
	if (all->map[i][j] == '0' || all->map[i][j] == '2'
		|| all->map[i][j] == 'N' || all->map[i][j] == 'S'
		|| all->map[i][j] == 'W' || all->map[i][j] == 'E')
	{
		if (all->map[i + 1][j] == ' ' || all->map[i - 1][j] == ' ' ||
			all->map[i][j + 1] == ' ' || all->map[i][j - 1] == ' ')
			err3();
	}
	else if (all->map[i][j] == ' ')
	{
		if ((all->map[i][j + 1] != ' ' && all->map[i][j + 1] != '1')
		|| (all->map[i][j - 1] != ' ' && all->map[i][j - 1] != '1')
		|| (all->map[i + 1][j] != ' ' && all->map[i + 1][j] != '1')
		|| (all->map[i - 1][j] != ' ' && all->map[i - 1][j] != '1'))
			err3();
	}
	else if (all->map[i][j] == '1')
		return ;
	else if (all->map[i][j] < 32)
		return ;
	else
		err3();
	return ;
}

int	parcechecker(t_all *all)
{
	int		i;
	int		j;
	int		sizew;
	int		sizeq;

	i = 0;
	sizew = (int)ft_strlen(all->map[i]);
	sizeq = all->rash->endmap - 1;
	check_kray1(all, 0);
	check_kray2(all, all->rash->endmap);
	check_kray3(all, 0);
	check_kray4(all, 0);
	j = 1;
	while ((j < sizeq - 1) && (j > 0))
	{
		i = 1;
		while ((i < sizew - 1) && (i > 0))
		{
			parcemap(j, i, all);
			i++;
		}
		j++;
	}
	return (1);
}
