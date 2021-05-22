/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:39:31 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 03:00:52 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_image_no(t_all *all, int **tex, char *path)
{
	all->text->north.img = mlx_xpm_file_to_image(all->vars->mlx, path,
			&all->text->texwe, &all->text->texhi);
	if (all->text->north.img == NULL)
		err2();
	all->text->north.addr = mlx_get_data_addr(all->text->north.img,
			&all->text->north.bits_per_pixel, &all->text->north.line_length,
			 &all->text->north.endian);
	*tex = (int *)all->text->north.addr;
}

void	load_image_so(t_all *all, int **tex, char *path)
{
	all->text->south.img = mlx_xpm_file_to_image(all->vars->mlx, path,
			&all->text->texwe, &all->text->texhi);
	if (all->text->south.img == NULL)
		err2();
	all->text->south.addr = mlx_get_data_addr(all->text->south.img,
			&all->text->south.bits_per_pixel, &all->text->south.line_length,
			&all->text->south.endian);
	*tex = (int *)all->text->south.addr;
}

void	load_image_ea(t_all *all, int **tex, char *path)
{
	all->text->east.img = mlx_xpm_file_to_image(all->vars->mlx, path,
			&all->text->texwe, &all->text->texhi);
	if (all->text->east.img == NULL)
		err2();
	all->text->east.addr = mlx_get_data_addr(all->text->east.img,
			&all->text->east.bits_per_pixel, &all->text->east.line_length,
			&all->text->east.endian);
	*tex = (int *)all->text->east.addr;
}

void	load_image_we(t_all *all, int **tex, char *path)
{
	all->text->west.img = mlx_xpm_file_to_image(all->vars->mlx, path,
			&all->text->texwe, &all->text->texhi);
	if (all->text->west.img == NULL)
		err2();
	all->text->west.addr = mlx_get_data_addr(all->text->west.img,
			&all->text->west.bits_per_pixel, &all->text->west.line_length,
			&all->text->west.endian);
	*tex = (int *)all->text->west.addr;
}

void	load_image_sp(t_all *all, int **tex, char *path)
{
	all->text->sprite.img = mlx_xpm_file_to_image(all->vars->mlx,
			path, &all->text->texwe, &all->text->texhi);
	if (all->text->sprite.img == NULL)
		err2();
	all->text->sprite.addr = mlx_get_data_addr(all->text->sprite.img,
			&all->text->sprite.bits_per_pixel, &all->text->sprite.line_length,
			&all->text->sprite.endian);
	*tex = (int *)all->text->sprite.addr;
}
