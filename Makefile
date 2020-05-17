NAME       = lem-in
FLAGS      = -Wall -Wextra -Werror -g -Ofast
SRC_DIR    = ./srcs/
OBJ_DIR    = ./obj/
INC_DIR    = ./includes/
LIBFT_DIR  = ./libft/
SRC_FILES  =  find.c finish.c init.c lemin.c main.c output.c runloop.c start.c
OBJ_FILES  = $(SRC_FILES:.c=.o)
SRC        = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ        = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT      = $(addprefix $(LIBFT_DIR), libft.a)
LNK        = -L $(LIBFT_DIR) -lft

all: obj $(LIBFT) $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	gcc $(FLAGS) -I $(LIBFT_DIR)/includes -I $(INC_DIR) -o $@ -c $<

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	gcc $(OBJ) $(LNK) -lm -o $(NAME)
#	gcc $(OBJ) $(LNK) -lm -fsanitize=address -o $(NAME)

clean:
	rm -Rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
