CC = cc
CFLAGS = -Wall -Wextra -Werror
MD = mkdir -p
RM = rm -f
RMDIR = rm -rf

NAME = push_swap

LIBFT_PATH = ./Library
LIBFT = $(LIBFT_PATH)/libft.a

SRC_PATH = src
OBJ_PATH = $(SRC_PATH)/obj

SRC = push_swap.c \
      parsing.c \
      swap.c push.c rotate.c reverse_rotate.c \
      error_handling.c

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

all: $(NAME)

$(OBJ_PATH):
	@$(MD) $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)
	@$(RMDIR) $(OBJ_PATH)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
