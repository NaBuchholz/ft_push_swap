# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 16:35:09 by nbuchhol          #+#    #+#              #
#    Updated: 2024/12/17 15:03:20 by nbuchhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Compilation definitions

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories definitions

INCLUDES = -Iincludes
SRCDIR = ./src

# Libft

DIR_LIBFT = libft
NAME_LIBFT = libft/libft.a
LINCLUDES = -L ${DIR_LIBFT} -lft

# Paths

SRC = ${SRCDIR}/push_swap.c
OBJDIR = ./objs
OBJ = ${patsubst ${SRCDIR}/%.c, ${OBJDIR}/%.o, ${SRC}}

# Extra definitions

RM = rm -rf

all: ${NAME}

${NAME_LIBFT}:
	@${MAKE} -C ${DIR_LIBFT}

$(NAME): $(NAME_LIBFT) $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(NAME_LIBFT) -o $(NAME) $(INCLUDES) $(LINCLUDES)
	@echo "| push_swap executable was generated successfully!! |"

${OBJDIR}:
	@mkdir -p ${OBJDIR}

${OBJDIR}/%.o: ${SRCDIR}/%.c
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
	${RM} ${OBJDIR}

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C $(DIR_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft
