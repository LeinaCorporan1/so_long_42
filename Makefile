# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorpora <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 18:26:25 by lcorpora          #+#    #+#              #
#    Updated: 2022/06/10 18:26:27 by lcorpora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

AR			=	ar rcs
RM			=	rm -f

MLX_DIR		=	mlx_linux/
LIBFT		=	libft/
HEADER		=	so_long.h

SRCS		=	src/so_long.c \
				src/utils.c \
				src/parsing.c \
				src/init.c \
				src/destroy.c \
				src/check_error.c \
				src/msg.c

OBJS		=	$(SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g3 -I/usr/include  -Imlx_linux -c $< -o $@

$(NAME)		:	$(OBJS)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT)
	@$(CC) -o $(NAME) $(OBJS) -L$(MLX_DIR)  -L$(LIBFT) -lft -Imlx_linux -lmlx -lXext -lX11 -lm -lz
all			:	$(NAME)

clean		:
	@make -C $(MLX_DIR) clean
	@$(RM) $(OBJS)

fclean		:	clean
	@$(RM) $(NAME)

re			:	clean all

cleand		:	all clean fclean re
