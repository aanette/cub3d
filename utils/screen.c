/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:52:58 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 03:59:45 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_screenshot2(int fd, t_all *all)
{
	int32_t	x;
	int32_t	y;
	int		color;

	y = all->rash->r2 - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < all->rash->r1)
		{
			color = *(unsigned int *)(all->img->addr
					+ (y * all->img->line_length)
					+ x * (all->img->bits_per_pixel / 8));
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
	close(fd);
	exit(0);
}

void	create_screenshot(t_all *all)
{
	int		fd;
	char	bitmap[54];

	fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	if (fd < 0)
	{
		write(2, "Error\nСreating a screenshot resulted in an error", 49);
		exit(-1);
	}
	ft_bzero(bitmap, 54);
	bitmap[0] = 'B';
	bitmap[1] = 'M';
	*((int *)(bitmap + 2)) = all->rash->r2 * all->rash->r1 * 4 + 54;
	*(int *)(bitmap + 10) = 54;
	*(int *)(bitmap + 14) = 40;
	*(int *)(bitmap + 18) = all->rash->r1;
	*(int *)(bitmap + 22) = all->rash->r2;
	*(bitmap + 26) = 1;
	*(bitmap + 28) = 32;
	write(fd, bitmap, 54);
	create_screenshot2(fd, all);
}

void	screenshot(t_all *all, char **argv)
{
	if (!ft_memcmp("--save", argv[2], 6))
		all->rash->flag = 1;
	else
	{
		write(1, "Error\n", 6);
		write(1, "Wrong flag for screenshot\n", 26);
		exit(-1);
	}
}
