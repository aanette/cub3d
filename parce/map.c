/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:43:09 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 03:21:39 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_num_sp(t_all *all)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (all->map[i])
	{
		j = 0;
		while ((i < all->rash->endmap) && (all->map[i][j]))
		{
			if (all->map[i][j] == '2')
				k++;
			j++;
		}
		i++;
	}
	return (k);
}

int	check_map(t_all *all)
{
	char	*d;
	int		x;
	int		y;

	x = 0;
	y = 0;
	d = ft_strchr(" 012WENS", all->map[y][x]);
	if (!d)
	{
		err1(all);
		return (-1);
	}
	else
		check(all);
	return (0);
}

void	map_header(t_all *all, int j)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(all->rash->map, O_RDONLY);
	while (i < all->rash->begmap)
	{
		get_next_line(fd, &line);
		free(line);
		i++;
	}
	i = 0;
	all->rash->endmap = j - all->rash->begmap;
	while (i <= all->rash->endmap)
	{
		get_next_line(fd, &all->map[i]);
		i++;
	}
	all->map[i] = 0;
	all->plr->dist = 0;
}

void	make_map(t_all *all)
{
	int		j;
	char	*line;

	line = 0;
	j = check_num_str(all);
	all->map = malloc((sizeof(char *) * (j - all->rash->begmap + 2)));
	if (!all->map)
	{
		all->rash->err = -1;
		free(line);
	}
	map_header(all, j);
	parcechecker(all);
	find_player(all);
	init(all);
	check_map(all);
}
