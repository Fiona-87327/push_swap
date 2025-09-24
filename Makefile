
NAME = push_swap
SRCS = src/array_sort.c src/check_util.c src/input_check.c src/oper_pu_sw.c src/oper_rev_rotate.c src/oper_rotate.c \
	   src/push_swap.c src/sort_util.c src/stack_sort.c
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Isrc

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re