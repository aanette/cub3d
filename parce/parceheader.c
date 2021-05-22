/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parceheader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:39:03 by aanette           #+#    #+#             */
/*   Updated: 2021/04/26 22:39:37 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_r(char *line, t_all *all)
{
	int		i;
	char	**map;

	i = 0;
	map = ft_split(line, ' ');
	if ((ft_strlentwo(map) != 3) || all->rash->r1 > -1)
		err2();
	while (map[i] != NULL)
	{
		if (ft_strchr(map[i], 'R'))
		{
			free(map[i]);
			all->rash->r1 = ft_atoi(map[++i]);
			free(map[i]);
			all->rash->r2 = ft_atoi(map[++i]);
			free(map[i]);
			all->rash->begmap++;
			break ;
		}
		free(map[i]);
		break ;
	}
	free(map);
}

void	check_f(char *line, t_all *all)
{
	int		i;
	char	**map;

	i = 0;
	map = ft_split(line, ',');
	if ((ft_strlentwo(map) != 3) || (all->rash->f1 > -1))
		err2();
	while (map[i] != NULL)
	{
		if (ft_strchr(map[i], 'F'))
		{
			all->rash->f1 = ft_atoi(map[i]);
			free(map[i++]);
			all->rash->f2 = ft_atoi(map[i]);
			free(map[i++]);
			all->rash->f3 = ft_atoi(map[i]);
			free(map[i]);
			all->rash->begmap++;
			break ;
		}
		break ;
	}
	free(map);
}

void	check_c(char *line, t_all *all)
{
	int		i;
	char	**map;

	i = 0;
	map = ft_split(line, ',');
	if ((ft_strlentwo(map) != 3) || (all->rash->c1 > -1))
		err2();
	while (map[i] != NULL)
	{
		if (ft_strchr(map[i], 'C'))
		{
			all->rash->c1 = ft_atoi(map[i]);
			free(map[i++]);
			all->rash->c2 = ft_atoi(map[i]);
			free(map[i++]);
			all->rash->c3 = ft_atoi(map[i]);
			free(map[i]);
			all->rash->begmap++;
			break ;
		}
		break ;
	}
	free(map);
}

void	check_s(char *line, t_all *all)
{
	int		i;
	char	**map;

	i = 0;
	map = ft_split(line, ' ');
	while (map[i] != NULL)
	{
		if (ft_strchr(map[i], 'S') && !(ft_strchr(map[i], '1') \
		|| ft_strchr(map[i], '0')))
		{
			if ((ft_strlentwo(map) != 2) || (all->rash->s))
				err2();
			free(map[i]);
			all->rash->s = map[++i];
			all->rash->begmap++;
			break ;
		}
		break ;
	}
	free(map);
}

void	parceparam(t_all *all)
{
	int		fd;
	char	*line;

	init_params(all);
	fd = open (all->rash->map, O_RDONLY);
	while ((get_next_line(fd, &line) > 0))
	{
		check_everything(line, all);
		free(line);
	}
	free(line);
	if (get_next_line(fd, &line) == -1)
		err2();
	free(line);
	check_params(all);
	close(fd);
}
