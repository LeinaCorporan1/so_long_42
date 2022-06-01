NAME		=	so_long

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

AR			=	ar rcs
RM			=	rm -f

MLX_DIR		=	mlx_linux/
LIBFT		=	../libft_42/
HEADER		=	so_long.h

SRCS		=	so_long.c \
				utils.c \
				parsing.c

OBJS		=	$(SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g3 -I/usr/include  -Imlx_linux -O3 -c $< -o $@

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