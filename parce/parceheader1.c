/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parceheader1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:40:08 by aanette           #+#    #+#             */
/*   Updated: 2021/04/24 23:04:25 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_no(char *line, t_all *all)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = ft_split(line, ' ');
	if (ft_strlentwo(map) != 2)
		err2();
	while (map[i] != NULL)
	{
		if ((map[i][j] == 'N') && (map[i][++j] == 'O'))
		{
			free(map[i]);
			all->rash->no = map[++i];
			all->rash->begmap++;
			break ;
		}
		else
			err2();
		break ;
	}
	free(map);
}

void	check_so(char *line, t_all *all)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = ft_split(line, ' ');
	if (ft_strlentwo(map) != 2)
		err2();
	while (map[i] != NULL)
	{
		if ((map[i][j] == 'S') && (map[i][++j] == 'O'))
		{
			free(map[i]);
			all->rash->so = map[++i];
			all->rash->begmap++;
			break ;
		}
		else
			err2();
		break ;
	}
	free(map);
}

void	check_ea(char *line, t_all *all)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = ft_split(line, ' ');
	if (ft_strlentwo(map) != 2)
		err2();
	while (map[i] != NULL)
	{
		if ((map[i][j] == 'E') && (map[i][++j] == 'A'))
		{
			free(map[i]);
			all->rash->ea = map[++i];
			all->rash->begmap++;
			break ;
		}
		else
			err2();
		break ;
	}
	free(map);
}

void	check_we(char *line, t_all *all)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = ft_split(line, ' ');
	if (ft_strlentwo(map) != 2)
		err2();
	while (map[i] != NULL)
	{
		if ((map[i][j] == 'W') && (map[i][++j] == 'E'))
		{
			free(map[i]);
			all->rash->we = map[++i];
			all->rash->begmap++;
			break ;
		}
		else
			err2();
		break ;
	}
	free(map);
}

void	check_everything(char *line, t_all *all)
{
	if (err(all) < 0)
		err2();
	if (ft_strchr(line, 'R'))
		check_r(line, all);
	else if ((ft_strchr(line, 'N') && ft_strchr(line, 'O')))
		check_no(line, all);
	else if ((ft_strchr(line, 'S') && ft_strchr(line, 'O')))
		check_so(line, all);
	else if ((ft_strchr(line, 'E') && ft_strchr(line, 'A')))
		check_ea(line, all);
	else if ((ft_strchr(line, 'W') && ft_strchr(line, 'E')))
		check_we(line, all);
	else if (ft_strchr(line, 'S'))
		check_s(line, all);
	else if (ft_strchr(line, 'C'))
		check_c(line, all);
	else if (ft_strchr(line, 'F'))
		check_f(line, all);
	else if (*line == '\n' || *line == '\0')
		all->rash->begmap++;
}
