# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sihemayoub <sihemayoub@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 15:00:14 by mayoub            #+#    #+#              #
#    Updated: 2023/07/19 17:20:26 by sihemayoub       ###   ########.fr        #
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

OBJS	= ${SRCS:.c=.o}

NAME	= 	so_long

CC		=	gcc 

CFLAGS	= -Werror -Wall -Wextra -g

RM		= rm -rf

%.o:	%.c
			${CC} ${CFLAGS} -o $< ${<:.c=.o}

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -framework OpenGL -framework AppKit -lmlx -o $(NAME)
			
all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
