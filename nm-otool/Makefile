# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 15:49:53 by tgrange           #+#    #+#              #
#    Updated: 2019/12/13 15:44:34 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NM_NAME =		nm

OTOOL_NAME =	otool

CC =			gcc

CFLAGS =		-Wall -Werror -Wextra -g

LIBFT_PATH =	Libft
LIBFT_NAME =	libft.a
LIBFTA =		$(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME))
LIBFT_INC =		$(LIBFT_PATH)/inc

INC_PATH =		inc
INC_NAME =		nm_otool.h
INC =			$(addprefix $(INC_PATH)/, $(INC_NAME))

SRC_PATH =		srcs
SRC_NAME =		

SRC =			$(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_PATH =		objs
OBJ_NAME =		$(SRC_NAME:.c=.o)
OBJ =			$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

all:			$(NAME)

$(NAME):		$(OBJ) $(INC) $(LIBFT) Makefile
	@make -C Libft
	@$(CC) $(SFLAG) $(OBJ) -o $(NAME) -L $(LIBFT_PATH) -lft
	@echo Compiled $(NAME)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH) -I $(LIBFT_INC)
	@echo Compiled $@

clean:
	@make -C Libft fclean
	@rm -rf $(OBJ_PATH)
	@echo Removed obj files

fclean:			clean
	@rm -rf $(NAME)
	@rm -rf $(LINKNAME)
	@echo Removed $(NAME)

re:				fclean all

.PHONY:			re fclean clean test
