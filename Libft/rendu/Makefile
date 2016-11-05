# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 18:25:11 by tgrange           #+#    #+#              #
#    Updated: 2016/11/05 12:17:35 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DOTC = ft_memset.c ft_bzero.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strncpy.c ft_strcat.c \
	   ft_strncat.c ft_strlcat.c

DOTO = ft_memset.o ft_bzero.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o \
	   ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_strncpy.o ft_strcat.o \
	   ft_strncat.c ft_strlcat.o

NAME = libft.a

FLAGS = -Wextra -Wall -Werror -c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(DOTC)
	ar rc $(NAME) $(DOTO)

clean:
	rm -rf $(DOTO)

fclean: clean
	rm $(NAME)

re: fclean all
