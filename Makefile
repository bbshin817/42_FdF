SRCS		=	src/main.c \
				src/math.c \
				src/coordinate_inits.c \
				src/coordinate_inits_2.c \
				src/image.c \
				src/image2.c \
				src/draw_line.c \
				src/map_inits.c \
				src/gradient.c \
				src/frees.c \
				get_next_line/get_next_line_utils.c \
				get_next_line/get_next_line.c
OBJS		=	$(SRCS:.c=.o)
NAME		=	FdF

LIBFT_DIR	=	libft
LIBFT_A		=	$(LIBFT_DIR)/libft.a

LIBMLX_A	=	mlx/libmlx_Linux.a

CC			=	cc
RM			=	rm -f
CFLAGS		=	-g -Wall -Wextra -Werror
MLX_CFLAGS	=	-Imlx -lXext -lX11

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(MLX_CFLAGS) $(OBJS) $(LIBFT_A) $(LIBMLX_A) -lm -o $(NAME)

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