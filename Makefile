
NAME = push_swap
SRCS = src/check_util.c src/input_check_util.c src/intput_check.c \
	   src/oper_rev_rotate.c src/oper_rotate.c src/sort_util.c src/k_sort.c \
	   src/stack_init.c src/oper_pop.c src/oper_sab.c src/small_sort.c
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean c:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean f: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

v : re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 1 5 2 4 21 435 234 546 567 78 43

re: fclean all

.PHONY: all clean fclean re

# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes