/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:24:03 by aanette           #+#    #+#             */
/*   Updated: 2021/04/27 03:41:30 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
//# include "mlx/mlx.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define SCREEN_SIZE_W 2560
# define SCREEN_SIZE_H 1440

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_pair
{
	double		first;
	int			second;
}				t_pair;

typedef struct s_spr
{
	float		*sprite_x;
	float		*sprite_y;
	float		*spritedist;
	int			spritenum;
	int			*spriteord;
	double		*zbuf;
	int			spritew;
	int			spriteh;
	double		sprx;
	double		spry;
	double		invdet;
	double		transx;
	double		transy;
	int			spritescreenx;
	int			drawstartx;
	int			drawstarty;
	int			drawendx;
	int			drawendy;
	int			texx;
	int			texy;
}				t_spr;

typedef struct s_param
{
	int			r1;
	int			r2;
	int			k;
	char		*map;
	int			begmap;
	int			endmap;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*s;
	int			c1;
	int			c2;
	int			c3;
	int			f1;
	int			f2;
	int			f3;
	int			pov;
	int			err;
	int			flag;
}				t_param;

typedef struct s_text
{
	int			texhi;
	int			texwe;
	int			texnum;
	int			texx;
	int			texy;
	float		wallx;
	float		texpos;
	t_data		north;
	t_data		south;
	t_data		east;
	t_data		west;
	t_data		sprite;
	int			*tex[5];
	double		step;
	int			color;
}				t_text;

typedef struct s_plr
{
	float		x;
	float		y;
	float		pos_x;
	float		pos_y;
	int			map_x;
	int			map_y;
	float		delta_distx;
	float		delta_disty;
	float		side;
	float		pwd;
	int			drawstart;
	int			drawend;
	float		ray_dir_x;
	float		ray_dir_y;
	float		dir_x;
	float		dir_y;
	double		side_dist_x;
	double		side_dist_y;
	float		x_plane;
	float		y_plane;
	int			hit;
	int			step_x;
	int			step_y;
	float		olddirx;
	float		oldplanex;
	float		camera_x;
	float		dist;
	double		movespeed;
	double		rotspeed;
	int			height;
}				t_plr;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct s_all
{
	t_param		*rash;
	t_spr		*spr;
	t_vars		*vars;
	t_data		*img;
	t_text		*text;
	char		**map;
	t_plr		*plr;
}				t_all;

int		ft_strlentwo(char **map);
void	err3(void);
void	err2(void);
int		err(t_all *all);
int		err1(t_all *all);

void	check_kray1(t_all *all, int i);
void	check_kray2(t_all *all, int i);
void	check_kray3(t_all *all, int i);
void	check_kray4(t_all *all, int i);
void	check_symb(t_all *all, int i, int j);

int		parcechecker(t_all *all);
void	parcemap(int i, int j, t_all *all);
void	check_arg(t_all *all, char **argv);

int		check(t_all *all);
int		check_pos_sprite(t_all *all);
int		check_num_str(t_all *all);
void	check_params(t_all *all);
void	init_params(t_all *all);

int		check_num_sp(t_all *all);
int		check_map(t_all *all);
void	map_header(t_all *all, int j);
void	make_map(t_all *all);

void	check_r(char *line, t_all *all);
void	check_f(char *line, t_all *all);
void	check_c(char *line, t_all *all);
void	check_s(char *line, t_all *all);
void	parceparam(t_all *all);

void	check_no(char *line, t_all *all);
void	check_so(char *line, t_all *all);
void	check_ea(char *line, t_all *all);
void	check_we(char *line, t_all *all);
void	check_everything(char *line, t_all *all);

void	load_tex(t_all *all);
void	drawtexture(t_all *all, int x);
void	draw1(t_all *all, int x, int y1, int y2);
void	draw_all_tex1(t_all *all, int x);
void	colorcheker(t_all *all, int x);

void	move_s(t_all *all);
void	move_w(t_all *all);
void	move_a(t_all *all);
void	move_d(t_all *all);

void	load_image_no(t_all *all, int **tex, char *path);
void	load_image_so(t_all *all, int **tex, char *path);
void	load_image_ea(t_all *all, int **tex, char *path);
void	load_image_we(t_all *all, int **tex, char *path);
void	load_image_sp(t_all *all, int **tex, char *path);

void	colona(t_all *all);
int		mainloop(t_all *all);
void	inittextvalue(t_all *all);
void	all_funk(t_all *all);
void	draw2(t_all *all, int x, int y1, int y2);

void	calc_step(t_all *all);
void	find_drawstart_end(t_all *all);
void	fisheye(t_all *all);
void	dda(t_all *all);
void	find_texture(t_all *all);

void	check_sprite_size(t_all *all);
void	transformation(t_all *all);
void	draw_sprite(t_all *all);
void	poehali(t_all *all);
int		ft_sprite_dist(t_all *all);

void	sort_order(t_pair *orders, int amount);
void	sort_sprite(int *order, float *dist, int amount);

void	init_s(t_all *all, int i, int j);
void	init_e(t_all *all, int i, int j);
void	init_w(t_all *all, int i, int j);
void	init_n(t_all *all, int i, int j);
void	init(t_all *all);

void	move_123(t_all *all);
void	move_124(t_all *all);
void	move_s(t_all *all);
void	move_a(t_all *all);
void	move_d(t_all *all);
void	move_w(t_all *all);

void	my_mlx_pixel_put(t_all *all, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
void	move_123(t_all *all);
void	move_124(t_all *all);
int		ft_close(int keycode, t_all *all);

void	find_player(t_all *all);
int		init_ev(t_all *all, int i, int j);
void	screenshot(t_all *all, char **argv);
void	create_screenshot(t_all *all);
void	create_screenshot2(int fd, t_all *all);

#endif