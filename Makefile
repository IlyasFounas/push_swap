NAME    = push_swap
SRC     = srcs/main.c \
		  srcs/instructions_a.c \
		  srcs/instructions_b.c \
		  srcs/instructions_a_b.c \
		  srcs/no_logical_search_best_move.c \
		  srcs/no_logical_rotate_n_push.c \
		  srcs/no_logical_sort.c \
		  srcs/rotate_with_gas_fee.c \
		  srcs/push_swap_utils.c \
		  srcs/no_logical_algo.c \
          ft_printf/ft_printf.c \
          ft_printf/ft_printf_utils.c 
OBJ_DIR = objs
OBJ     = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
CFLAGS  = -Wall -Wextra -Werror -g3 -I/usr/include -I../libft/includes -I includes
CC      = cc

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(LIBFT) $(OBJ)  Makefile ft_printf/ft_printf.h includes/push_swap.h $(LIBFT_DIR)/libft.h
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: ft_printf/%.c ft_printf/ft_printf.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): force
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

run: $(NAME)
	valgrind ./$(NAME) -14 10 -201 18 2 78 -63 10005 -52 -10000 -85 95 22 21

all: $(NAME)

force:

.PHONY: all clean fclean re run

