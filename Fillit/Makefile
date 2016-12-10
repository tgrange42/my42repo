# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 02:11:01 by tgrange           #+#    #+#              #
#    Updated: 2016/12/09 23:31:21 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

dotC = main.c get_tetro.c verif.c verif_test.c tetro_or_not_tetro.c do_it_just_do_it.c \
	   place_piece.c

dotO = $(dotC:.c=.o)

NAME = fillit

FLAGS = -g -Wall -Werror -Wextra -Weverything

LIB = Libft/libft.a

all: $(NAME)

$(NAME): $(dotO)
	make -C ./Libft
	gcc $(FLAGS) -o $(NAME) $(dotO) $(LIB)

%.o: %.c
		@gcc -o $@ -c $< $(FLAGS)
clean:
	rm -rf $(dotO)
	make -C ./Libft clean

fclean: clean
	rm $(NAME)
	make -C Libft fclean

re: fclean all
