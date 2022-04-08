# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 15:00:14 by mayoub            #+#    #+#              #
#    Updated: 2022/04/08 05:55:05 by mayoub           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	get_next_line.c \
			get_next_line_utils.c \
			ft_split.c \
			parsing.c \
			main.c \
			mlx_window.c \
			mlx_ini_sprites.c \
			put_image.c \
			deplacement.c \

OBJS	= ${SRCS:.c=.o}

NAME	= 	so_long

CC		=	gcc 

CFLAGS	= -Werror -Wall -Wextra -g

RM		= rm -rf

%.o:	%.c
			${CC} ${CFLAGS} -o $< ${<:.c=.o}

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -framework OpenGL -framework AppKit -fsanitize=address -lmlx -o $(NAME)
			
all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
