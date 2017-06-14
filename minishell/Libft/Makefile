# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 18:25:11 by tgrange           #+#    #+#              #
#    Updated: 2017/04/13 05:00:55 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

src = ft_memset.c ft_bzero.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strncpy.c ft_strcat.c \
	   ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_putchar.c ft_putstr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c \
	   ft_putendl_fd.c ft_itoa.c ft_putnbr.c ft_putnbr_fd.c ft_countchar.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	   ft_strdel.c ft_strclr.c ft_strtrim.c ft_strjoin.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_countav.c ft_strsplit.c \
	   ft_strmap.c ft_strmapi.c ft_striter.c ft_striteri.c ft_memcmp.c ft_memchr.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_revstr.c ft_itoa_base.c ft_putnbr_base.c \
	   ft_lstincre.c ft_sqrt.c ft_strlento.c ft_swap.c ft_swaplst.c ft_swapptr.c ft_print_char.c ft_putbegl.c ft_tablen.c \
	   ft_putstr_space.c get_next_line.c

obj = $(src:.c=.o)

NAME = libft.a

flags = -Wextra -Wall -Werror -c

all: $(NAME)

$(NAME): $(obj)
	@ar rc $(NAME) $(obj)
	@ranlib $(NAME)

%.o: %.c
	@gcc -o $@ -c $< $(flags)

clean:
	@rm -rf $(obj)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
