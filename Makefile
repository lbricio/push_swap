# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 03:01:43 by lbricio-          #+#    #+#              #
#    Updated: 2021/10/14 03:05:07 by lbricio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=	./src
SRC		=	push_swap.c \
			check_args.c \
			mov_01.c \
			mov_02.c \
			solve_01.c \
			solve_02.c \
			sort_inv.c \
			utils_01.c \

OBJ_DIR	=	./builds
OBJ		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

INCD_DIR=	./include
INCD	=	push_swap.h

vpath %.c $(SRC_DIR)
vpath %.h $(INCD_DIR)

NAME	=	push_swap

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

CC		=	clang

all:			$(NAME)

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o:	%.c $(INCD)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c -o $@ $(CFLAGS) -I $(INCD_DIR) $<
	@echo "  Criando .o de "$<

clean:
	@$(RM) $(OBJ_DIR)

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all

git:
	git add .
	git status
	git commit -m "$m"

.PHONY:		all clean fclean re git
