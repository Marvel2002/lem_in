NAME = lem-in
CC = gcc
INCLUDE = -Ilibft -Iinclude
CFLAGS = -Wall -Werror -Wextra -fsanitize=address $(INCLUDE)
SRC_PS = src/main.c src/analyse_args.c src/free.c src/init_env.c src/init_link.c src/init_list_room.c src/init_list_stdin.c src/parsing.c src/set_path.c src/solver.c src/utils_list.c src/utils_parsing.c src/valid_all_params.c
LIB_PATH = ./libft/
LIB_BIN = $(LIB_PATH)libft.a
SRC_PATH = ./src/

OBJ_SRC_PS = $(SRC_PS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SRC_PS)
	make -C $(LIB_PATH)
	$(CC) -o $(NAME) $(SRC_PS) $(INCLUDE) $(CFLAGS) $(LIB_BIN)

clean:
	make -C $(LIB_PATH) clean
	/bin/rm -f $(OBJ_SRC_PS)

fclean: clean
	make -C $(LIB_PATH) fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
