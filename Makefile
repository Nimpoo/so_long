# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sihemayoub <sihemayoub@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 15:00:14 by mayoub            #+#    #+#              #
#    Updated: 2023/07/19 17:45:42 by sihemayoub       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	src/parsing.c					\
			src/main.c						\
			src/mlx_window.c				\
			src/mlx_ini_sprites.c			\
			src/put_image.c					\
			src/deplacement.c				\
			src/kill_window.c				\
			src/check_key.c					\
			src/vilain.c					\
			src/utils/get_next_line.c		\
			src/utils/get_next_line_utils.c	\
			src/utils/ft_split.c			\
			src/utils/ft_itoa.c				\

OBJS	=	${SRCS:.c=.o}

NAME	= 	so_long

CC		=	gcc 

CFLAGS	=	-Werror -Wall -Wextra -g

RM		=	rm -rf

$(NAME):	minilibx/libmlx.a $(OBJS)
			$(CC) $(CFLAGS) -Lminilibx -framework Opengl -framework Appkit minilibx/libmlx.a $(OBJS) -o $(NAME)
			
minilibx:	
			curl https://raw.githubusercontent.com/Nimpoo/cub3d/dev/minilibx.tgz -o minilibx.tgz
			tar -xf minilibx.tgz
			rm minilibx.tgz
			make -C minilibx
			
all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

fclean_mlx:
			${RM} minilibx

re:			fclean all

.PHONY:		minilibx all clean fclean re
