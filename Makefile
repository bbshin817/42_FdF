SRCS		=	src/main.c \
				get_next_line/get_next_line_utils.c \
				get_next_line/get_next_line.c
OBJS		=	$(SRCS:.c=.o)
NAME		=	fdf

LIBFT_DIR	=	libft
LIBFT_A		=	$(LIBFT_DIR)/libft.a

LIBMLX_A	=	mlx/libmlx_Linux.a

CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
MLX_CFLAGS	=	-Imlx -lXext -lX11

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(MLX_CFLAGS) $(OBJS) $(LIBFT_A) $(LIBMLX_A) -o $(NAME)

all: $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean	all

.PHONY:	all clean fclean re