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

ARCHIVE_URL = https://cdn.intra.42.fr/document/document/34607/minilibx-linux.tgz
ARCHIVE_NAME = minilibx-linux.tgz
LIBMLX_DIR = mlx/
LIBMLX_A	=	mlx/libmlx_Linux.a

LIBFT_DIR	=	libft
LIBFT_A		=	$(LIBFT_DIR)/libft.a

CC			=	cc
RM			=	rm -f
CFLAGS		=	-g -Wall -Wextra -Werror
MLX_CFLAGS	=	-Imlx -lXext -lX11

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBMLX_DIR) $(LIBMLX_A) $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(MLX_CFLAGS) $(OBJS) $(LIBFT_A) $(LIBMLX_A) -lm -o $(NAME)

$(LIBMLX_DIR): $(ARCHIVE_NAME)
	mkdir -p $(LIBMLX_DIR)
	tar -xzf $(ARCHIVE_NAME) --strip-components=1 -C $(LIBMLX_DIR)

$(ARCHIVE_NAME):
	wget $(ARCHIVE_URL)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX_A): $(LIBMLX_DIR)
	$(MAKE) -C $(LIBMLX_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean	all

.PHONY:	all clean fclean re $(LIBMLX_DIR)