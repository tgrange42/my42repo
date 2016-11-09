# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 18:25:11 by tgrange           #+#    #+#              #
#    Updated: 2016/11/08 14:33:42 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DOTC = ft_memset.c ft_bzero.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strncpy.c ft_strcat.c \
	   ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_putchar.c ft_putstr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c \
	   ft_putendl_fd.c ft_itoa.c ft_putnbr.c ft_putnbr_fd.c ft_countchar.c ft_strlento.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	   ft_strdel.c ft_strclr.c ft_strtrim.c ft_strsplit.c ft_strjoin.c ft_strequ.c ft_strnequ.c ft_strsub.c

DOTO = ft_memset.o ft_bzero.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o \
	   ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_strncpy.o ft_strcat.o \
	   ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_putchar.o ft_putstr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl.o \
	   ft_putendl_fd.o ft_itoa.o ft_putnbr.o ft_putnbr_fd.o ft_countchar.o ft_strlento.o ft_memalloc.o ft_memdel.o ft_strnew.o \
	   ft_strdel.o ft_strclr.o ft_strtrim.o ft_strsplit.o ft_strjoin.o ft_strequ.o ft_strnequ.o ft_strsub.o

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
