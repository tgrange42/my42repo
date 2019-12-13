# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgrange <tgrange@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 18:25:11 by tgrange           #+#    #+#              #
#    Updated: 2019/10/11 14:53:36 by tgrange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libft.a

CFLAGS =			-Wextra -Wall -Werror -g

INC_PATH =			inc
INC_NAME =			libft.h
INC =				$(addprefix $(INC_PATH)/, $(INC_NAME))

SRC_PATH =			srcs
SRC_NAME =			ft_bzero.c ft_memset.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
					ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strncpy.c ft_strcat.c \
					ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_putchar.c ft_putstr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c \
					ft_putendl_fd.c ft_itoa.c ft_putnbr.c ft_putnbr_fd.c ft_countchar.c ft_memalloc.c ft_memdel.c ft_strnew.c \
					ft_strdel.c ft_strclr.c ft_strtrim.c ft_strjoin.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_countav.c ft_strsplit.c \
					ft_strmap.c ft_strmapi.c ft_striter.c ft_striteri.c ft_memcmp.c ft_memchr.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
					ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_revstr.c ft_itoa_base.c ft_putnbr_base.c \
					ft_lstincre.c ft_sqrt.c ft_strlento.c ft_swap.c ft_swaplst.c ft_swapptr.c ft_print_char.c ft_putbegl.c ft_tablen.c \
					ft_putstr_space.c get_next_line.c ft_strlento2.c ft_tabsplit.c ft_uint_putnbr.c ft_ulong_putnbr.c
SRC =				$(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_PATH =			objs
OBJ_NAME =			$(SRC_NAME:.c=.o)
OBJ =				$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

all:				$(NAME)

$(NAME):			Makefile $(INC) $(OBJ)	
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo Compiled $(NAME)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAGS) -o $@ -c $< -I $(INC_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@echo Removed obj files

fclean:			clean
	@rm -rf $(NAME)
	@echo Removed $(NAME)

re:					fclean all clean
