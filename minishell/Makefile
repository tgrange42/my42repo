# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 14:52:31 by tgrange           #+#    #+#              #
#    Updated: 2017/06/07 15:27:41 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minishell

SRCS =		srcs/minishell.c

CFLAGS =	-Wall -Weverything -Werror

OBJS =		$(addprefix objs/, $(notdir $(SRCS:.c=.o)))

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C libft
			@gcc $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft
			@echo Done !

objs/%.o:	srcs/%.c
			@gcc -o $@ -c $< $(CFLAGS)
clean:
			@rm -rf $(OBJS)
			@make clean -C libft

fclean:		clean
			@rm -rf $(NAME)
			@make fclean -C libft

re:			fclean all

.PHONY:		re fclean clean