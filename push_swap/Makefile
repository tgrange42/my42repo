# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/04 13:41:28 by tgrange           #+#    #+#              #
#    Updated: 2020/09/04 14:24:59 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN_NAME =			push_swap

CC =				gcc

CFLAGS =			-Wall -Werror -Wextra

LIBFT_PATH =		Libft
LIBFT_NAME =		libft.a
LIBFTA =			$(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME))
LIBFT_INC =			$(LIBFT_PATH)/inc

INC_PATH =			inc
INC_NAME =			push_swap.h
INC =				$(addprefix $(INC_PATH)/, $(INC_NAME))

SRC_PATH =			srcs
SRC_NAME =			push_swap.c

SRC =				$(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_PATH =			objs
OBJ_NAME =			$(SRC_NAME:.c=.o)
OBJ =				$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

all:				$(BIN_NAME)

$(BIN_NAME):		get_libft $(OBJ) $(INC) $(LIBFT) Makefile
	@make -C Libft
	@$(CC) $(CFLAG) $(OBJ) -o $(BIN_NAME) -L $(LIBFT_PATH) -lft
	@echo Compiled $(BIN_NAME)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH) -I $(LIBFT_INC)
	@echo Compiled $@

get_libft:
	@make -C Libft

clean:
	@make -C Libft fclean
	@rm -rf $(OBJ_PATH)
	@echo Removed obj files

fclean:				clean
	@rm -rf $(NAME)
	@echo Removed $(NAME)

re:					fclean all

.PHONY:				re fclean clean test