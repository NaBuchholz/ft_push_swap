# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 15:00:00 by nbuchhol          #+#    #+#              #
#    Updated: 2025/04/13 20:24:30 by nbuchhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = $(LIBFT_DIR)/printf

SRC_DIR = src
OBJ_DIR = obj
INCLUDES_DIR = includes

SRC_FILES = push_swap.c \
		parse_args.c \
		push_operations.c \
		swap_operations.c \
		rotate_operations.c \
		rotate_reverse_operations.c \
		radix_sort.c \
		sort_hundred.c \
		validation.c \
		sort_stack.c \
		utils.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

DEPS = $(OBJS:.o=.d)
INC = -I$(INCLUDES_DIR) -I$(LIBFT_DIR)

DEPFLAGS = -MMD -MP

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF_DIR)/libftprintf.a -o $(NAME)
	@echo "| Push Swap Was Generated Successfully!! |"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ] || [ ! -f "$(LIBFT_DIR)/.git" ]; then \
		echo "Initializing libft submodule..."; \
		git submodule update --init --recursive $(LIBFT_DIR); \
	else \
		echo "Updating libft submodule..."; \
		BRANCH=$$(git config -f .gitmodules --get submodule.$(LIBFT_DIR).branch || echo "main"); \
		(cd $(LIBFT_DIR) && git checkout $$BRANCH && git pull origin $$BRANCH); \
	fi
	@make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re bonus
