# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 03:59:22 by tgrange           #+#    #+#              #
#    Updated: 2017/04/05 19:18:40 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_ls

CFLAGS =	-Wall -Wextra -Werror

SRC =		ft_ls.c lscore.c flags_ls.c tools.c error_ls.c list_ls.c time.c \
			collect_infos.c display.c display2.c clean_ls.c

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C libft
			@gcc $(CFLAGS) -o $(NAME) $(OBJ) -L libft -lft
			@echo Done !
clean:
			@rm -rf $(OBJ)
			@make clean -C libft

%.o: %.c
			@gcc -o $@ -c $< $(CFLAGS)

fclean:		clean
			@rm -rf $(NAME)
			@make fclean -C libft

re:			fclean all

.PHONY: re fclean clean
