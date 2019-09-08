NAME = push_swap
SRC_DIR = ./src
SRC = src/checker.c src/execute_command.c src/free_stack.c src/get_ops.c src/insertion_sort.c src/misc.c src/push_swap.c src/raise_error.c src/read_stack.c
SRC_ps = src/execute_command.c src/free_stack.c src/get_ops.c src/insertion_sort.c src/misc.c src/push_swap.c src/raise_error.c src/read_stack.c
SRC_ch = src/checker.c src/execute_command.c src/free_stack.c src/get_ops.c src/insertion_sort.c src/misc.c src/raise_error.c src/read_stack.c

OBJ_DIR = ./objs
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_ps = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_ps))
OBJ_ch = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_ch))
INC_DIR	:= include
LIBFT_DIR = libft
LIBFT_INC_DIR = $(LIBFT_DIR)/include

all: $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	echo $INC_DIR
	@gcc -Wall -Werror -Wextra -I$(LIBFT_INC_DIR) -I$(INC_DIR) -o $@ -c $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C $(LIBFT_DIR)
	@gcc -Wall -Werror -Wextra  -L $(LIBFT_DIR) -l ft -o $(NAME) $(OBJ_ps) -I$(LIBFT_INC_DIR) -I$(INC_DIR)
	@gcc -Wall -Werror -Wextra  -L $(LIBFT_DIR) -l ft -o checker $(OBJ_ch) -I$(LIBFT_INC_DIR) -I$(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f checker
	@make -C $(LIBFT_DIR) fclean

re: fclean all