# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 02:02:23 by msosnova          #+#    #+#              #
#    Updated: 2021/12/03 17:38:35 by msosnova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ANAME=libft.a
CFLAGS=-c -Wall -Werror -Wextra
CC=gcc

SRC=$(wildcard *.c)
OBJ_BONUS	=	ft_lstnew.o		\
			ft_lstadd_front.o	\
			ft_lstsize.o		\
			ft_lstlast.o		\
			ft_lstadd_back.o	\
			ft_lstdelone.o		\
			ft_lstclear.o		\
			ft_lstiter.o		\
			ft_lstmap.o

#OBJ_ALL=$(patsubst %.c, %.o, $(SRC))
#OBJ_NO_BONUS=$(filter-out $(OBJ_BONUS),$(OBJ_ALL))
OBJ_NO_BONUS	=	ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o\
			ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o\
			ft_itoa.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o\
			ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o\
			ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o\
			ft_strdup.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o\
			ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o\
			ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o\
			ft_toupper.o

all: $(ANAME)

#--> for libft-unit-test
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ_NO_BONUS) $(OBJ_BONUS)
#<--

bonus: $(OBJ_BONUS) $(ANAME)
	ar rcs $(ANAME) $(OBJ_NO_BONUS) $(OBJ_BONUS)

$(ANAME):$(OBJ_NO_BONUS)
	ar rcs $(ANAME) $(OBJ_NO_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ_NO_BONUS) $(OBJ_BONUS)

fclean: clean
	rm -f $(ANAME)

re: fclean all

.PHONY:	all bonus clean fclean re
