# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 03:59:22 by tgrange           #+#    #+#              #
#    Updated: 2017/03/17 16:01:10 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_ls

CFLAGS =	-Wall -Wextra -Werror

SRC =		SRC/ft_ls.c \
			SRC/lscore.c \
			SRC/flags_ls.c \
			SRC/path.c \
			SRC/error_ls.c \
			SRC/list_ls.c \
			SRC/collect_infos.c \

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C libft
			@gcc $(CFLAGS) -o $(NAME) $(OBJ) -L libft -lft
clean:
			@rm -rf $(OBJ)
			@make clean -C libft

%.o: %.c
			@gcc -o $@ -c $< $(CFLAGS)

fclean:		clean
			@rm -rf $(NAME)
			@make fclean -C libft

re:			fclean all
