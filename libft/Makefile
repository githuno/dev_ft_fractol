# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: runoki <runoki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 20:25:33 by runoki            #+#    #+#              #
#    Updated: 2023/12/08 20:25:51 by runoki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_printf.c print_int.c \
		print_unsigned.c print_char.c print_str.c \
		print_multihex.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_bzero.c \
		ft_strlen.c ft_strncmp.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
