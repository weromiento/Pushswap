NAME      = push_swap
CC        = cc
CFLAGS    = -Wall -Wextra -Werror
SRC_DIR   = src
OBJ_DIR   = obj
INC_DIR   = include
SRC       = push_swap.c error.c init_stack.c parse_flags.c bench.c\
			utils.c utils_find.c \
			push.c swap.c rotate.c reverse_rotate.c \
			short_sorts.c simple_sort.c medium_sort.c complex_sort.c
SRCS      = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ       = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
RM        = rm -f
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I $(INC_DIR) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

