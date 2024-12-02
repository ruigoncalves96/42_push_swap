CC = cc
CFLAGS = -Wall -Wextra -Werror
MD = mkdir -p
RM = rm -f
RMDIR = rm -rf

NAME = push_swap
NAME_BONUS = checker

LIBFT_PATH = ./Library
LIBFT = $(LIBFT_PATH)/libft.a

SRC_PATH = src
OBJ_PATH = $(SRC_PATH)/obj
SRC_BONUS_PATH = bonus
OBJ_BONUS_PATH = $(SRC_BONUS_PATH)/obj

SRC = push_swap.c \
      parsing.c push_atoi.c \
      swap.c push.c rotate.c reverse_rotate.c \
      algorithm.c algorithm_utils.c optimize_stacks.c move_algorithm.c lis.c\
      error_handling.c

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

BONUS = checker.c \
      	parsing.c push_atoi.c \
	swap.c push.c rotate.c reverse_rotate.c \
	algorithm_utils.c \
      	error_handling.c

OBJ_BONUS = $(addprefix $(OBJ_BONUS_PATH)/, $(BONUS:.c=.o))

all: $(NAME)

bonus: $(NAME) $(NAME_BONUS)

$(OBJ_BONUS_PATH):
	@$(MD) $(OBJ_BONUS_PATH)

$(OBJ_BONUS_PATH)/%.o: $(SRC_BONUS_PATH)/%.c | $(OBJ_BONUS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

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
	@$(RM) $(OBJ_BONUS)
	@$(RMDIR) $(OBJ_PATH)
	@$(RMDIR) $(OBJ_BONUS_PATH)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
