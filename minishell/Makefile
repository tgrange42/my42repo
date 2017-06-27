# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 14:52:31 by tgrange           #+#    #+#              #
#    Updated: 2017/06/27 17:54:37 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minishell

SRCS =		minishell.c \
			cd.c \
			mini_core.c \
			env.c \
			env_list.c \
			tools.c \
			env_functions.c \
			echo.c \
			pwd.c \
			exit_ms.c \

SRCSD =		$(addprefix srcs/, $(notdir $(SRCS)))

CFLAGS =	-Wall -Wextra -Werror

OBJS =		$(addprefix objs/, $(notdir $(SRCSD:.c=.o)))

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C libft
			@gcc $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft
			@echo $(NAME) done !

objs/%.o:	srcs/%.c
			@gcc -o $@ -c $< $(CFLAGS)
			@echo $@ done !
clean:
			@rm -rf $(OBJS)
			@make clean -C libft

fclean:		clean
			@rm -rf $(NAME)
			@make fclean -C libft

re:			fclean all

.PHONY:		re fclean clean
