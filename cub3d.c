/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:45:51 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 02:29:29 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_all	*initone(t_all *all, int argc, char **argv)
{
	t_plr		*plr;
	t_text		*text;
	t_param		*rash;
	t_spr		*spr;

	plr = (t_plr *)malloc(sizeof (t_plr));
	text = (t_text *)malloc(sizeof (t_text));
	rash = (t_param *)malloc(sizeof (t_param));
	spr = (t_spr *)malloc(sizeof (t_spr));
	all->plr = plr;
	all->rash = rash;
	all->text = text;
	all->spr = spr;
	if ((argc == 3) || (argc == 2))
		check_arg(all, argv);
	parceparam(all);
	return (all);
}

void	risuem(t_all *all)
{
	t_vars		*vars;
	t_data		*img;

	vars = (t_vars *)malloc(sizeof (t_vars));
	img = (t_data *)malloc(sizeof (t_data));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window (vars->mlx,
			all->rash->r1, all->rash->r2, "cub3d");
	img->img = mlx_new_image(vars->mlx, all->rash->r1, all->rash->r2);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	all->img = img;
	all->vars = vars;
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof (t_all));
	all = initone(all, argc, argv);
	if (all->rash->err < 0)
		return (err(all));
	risuem(all);
	make_map(all);
	init(all);
	if (all->rash-> err < 0)
		return (err(all));
	load_tex(all);
	ft_sprite_dist(all);
	mlx_loop_hook(all->vars->mlx, &mainloop, all);
	mlx_hook(all->vars->win, 2, 1L << 0, &ft_close, all);
	mlx_loop(all->vars->mlx);
}
