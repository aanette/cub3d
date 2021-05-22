# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 14:41:54 by aanette           #+#    #+#              #
#    Updated: 2021/04/27 03:40:59 by aanette          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME   = cub3D
SRCS   = cub3d.c libft/ft_atoi.c libft/ft_split.c libft/ft_strchr.c libft/ft_isalpha.c libft/ft_bzero.c libft/ft_memcmp.c\
			gnl/get_next_line.c gnl/get_next_line_utils.c \
			utils/utils_mlx.c utils/hooki.c utils/utils_player.c utils/raycasting.c utils/utils_init.c utils/loading.c utils/sprite.c\
			utils/drawev.c utils/raycasting2.c utils/sprite2.c utils/screen.c\
			parce/map.c parce/parceheader.c parce/parceheader1.c parce/error.c parce/check_map.c parce/parcemap.c  parce/parcemap2.c


OBJS   = $(SRCS:.c=.o)

CC    = gcc

RM    = rm -f

CFLAGS   = -O3 -Wall -Wextra -Werror -I./
DFLAGS   = -g -I./
LIBS   = -lmlx -framework OpenGL -framework AppKit -lm

MLX    = libmlx.a


all:   $(NAME)

$(NAME):  $(MLX) $(SRCS) cub3d.h
	${CC} -o $(NAME) $(DFLAGS) ${LIBS} ${SRCS}

$(MLX):

	@$(MAKE) -C mlx

	@mv mlx/$(MLX) .

clean:

	@$(MAKE) -C mlx clean

	$(RM) $(OBJS)
norm:
	norminette $(SRCS) cub3d.h
fclean:   clean

	$(RM) $(NAME) $(MLX)

re:    fclean $(NAME)

.PHONY:   all clean fclean re
