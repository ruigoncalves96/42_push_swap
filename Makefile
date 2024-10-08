CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap

LIBFT_PATH = ./Library
LIBFT = $(LIBFT_PATH)/libft.a

SRC_PUSH_SWAP = test.c
OBJ_PUSH_SWAP = test.o

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_PUSH_SWAP)
	@$(CC) $(SRC_PUSH_SWAP) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ_PUSH_SWAP)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
