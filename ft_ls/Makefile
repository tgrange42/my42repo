# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 03:59:22 by tgrange           #+#    #+#              #
#    Updated: 2017/06/09 16:27:25 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_ls

CFLAGS =	-Wall -Wextra -Werror

SRCS =		srcs/ft_ls.c srcs/lscore.c srcs/flags_ls.c srcs/tools.c \
			srcs/error_ls.c srcs/list_ls.c srcs/time.c srcs/collect_infos.c \
			srcs/display.c srcs/display2.c srcs/clean_ls.c srcs/display3.c \
			srcs/tools2.c

OBJS =		$(addprefix objs/, $(notdir $(SRCS:.c=.o)))

all:		objs $(NAME)

$(NAME):	$(OBJS)
			@make -C libft
			@gcc $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft
			@echo Done !
clean:
			@rm -rf objs
			@make clean -C libft

objs:
			@mkdir objs

objs/%.o: srcs/%.c
			@gcc -o $@ -c $< $(CFLAGS)
			@echo $< compiled !

fclean:		clean
			@rm -rf $(NAME)
			@make fclean -C libft

re:			fclean all

.PHONY: re fclean clean
