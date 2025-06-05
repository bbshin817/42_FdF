SRCS =	main.c
OBJS	= $(SRCS:.c=.o)
NAME	= fdf

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF_A = $(PRINTF_DIR)/libftprintf.a

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_A) $(PRINTF_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

all: $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_A):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re:	fclean	all

.PHONY:	all clean fclean re