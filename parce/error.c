/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:49:07 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 03:22:54 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlentwo(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
			j++;
		i++;
	}
	return (i);
}

void	err3(void )
{
	write(1, "Error\n", 6);
	write(1, "Invalid map\n", 12);
	exit (0);
}

void	err2(void )
{
	write(1, "Error\n", 6);
	exit (0);
}

int	err(t_all *all)
{
	if (all->rash->err < 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return (all->rash->err);
}

int	err1(t_all *all)
{
	all->rash->err = -2;
	return (err(all));
}
